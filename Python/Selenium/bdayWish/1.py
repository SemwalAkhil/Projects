"""
Send message across multiple platforms:
    1. Whatsapp
    2. Instagram
    3. Snapchat
    4. SMS
    5. Email
    6. Telegram
"""
# birthday_sender.py
import os
import time
import smtplib
import ssl
from email.message import EmailMessage
from typing import Dict, Any, List
from datetime import datetime
from dotenv import load_dotenv

import requests
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC


from telethon import TelegramClient

# ============= CONFIG =============

load_dotenv(".env.local")

# BIRTHDAY_TEMPLATE = input("Enter message : ")
# NAME = input("Enter name : ")
# IG_USER = input("Enter insta id : ")
# SC_ID = input("Enter sc id : ")
# TG_ID = input("Enter tg (numeric) id :")
# EMAIL = input("Enter email : ")
# PHONE = input("Enter phone number : ")
# DATE = input("Enter date (MM-DD) : ")
# SUBJECT = input("Subject of mail: ")

BIRTHDAY_TEMPLATE = "hello"
NAME = "akhil"
IG_USER = "semwal_akhil"
SC_ID = "anshikkk.aaa"
TG_ID = "SemwalAkhil"
EMAIL = "akhil392semwal@gmail.com"
PHONE = "9888820632"
DATE = "12-11"
SUBJECT = "hello"

# Example contact list.
# Fill only what you actually use for each person.
CONTACTS: List[Dict[str, Any]] = [
    {
        "name": NAME,
        "platforms": ["whatsapp", "instagram", "telegram", "email"],
        "whatsapp_name": NAME,                 # name as it appears on WhatsApp
        "instagram_username": IG_USER,      # IG username
        "snapchat_username": SC_ID,               # or username
        "telegram_username": TG_ID,         # numeric chat id
        "email": EMAIL,
        "phone": PHONE,                           # for SMS, e.g. "+91XXXXXXXXXX"
        "birthday": DATE,                      # MM-DD format (example)
        "subject": SUBJECT
    },
]

# ============= TEMPLATES / HELPERS =============

def personalize(name: str) -> str:
    return BIRTHDAY_TEMPLATE.format(name=name)


# ============= API PART: EMAIL + TWILIO SMS =============

# --- Email via Gmail SMTP ---
EMAIL_SENDER = os.getenv("EMAIL_SENDER")   # your Gmail
print(EMAIL_SENDER)
EMAIL_PASS = os.getenv("EMAIL_PASS")       # app password
print(EMAIL_PASS)

# --- Twilio SMS ---
TWILIO_ACCOUNT_SID = os.getenv("TWILIO_ACCOUNT_SID")
print(TWILIO_ACCOUNT_SID)
TWILIO_AUTH_TOKEN = os.getenv("TWILIO_AUTH_TOKEN")
print(TWILIO_AUTH_TOKEN)
TWILIO_FROM_SMS = os.getenv("TWILIO_FROM_SMS")  # e.g. +1XXXX or trial number
print(TWILIO_FROM_SMS)

from twilio.rest import Client as TwilioClient

def send_sms(to_number: str, text: str):
    if not (TWILIO_ACCOUNT_SID and TWILIO_AUTH_TOKEN and TWILIO_FROM_SMS):
        return False, "Twilio SMS not configured"
    try:
        client = TwilioClient(TWILIO_ACCOUNT_SID, TWILIO_AUTH_TOKEN)
        message = client.messages.create(
            from_=TWILIO_FROM_SMS,
            body=text,
            to=to_number
        )
        return True, message.sid
    except Exception as e:
        return False, str(e)
# EMAIL_SENDER = os.getenv("EMAIL_SENDER")   # your Gmail
# EMAIL_PASS = os.getenv("EMAIL_PASS")       # app password


def send_email(recipient: str, subject: str, body: str):
    if not EMAIL_SENDER or not EMAIL_PASS:
        return False, "EMAIL_SENDER or EMAIL_PASS not set"

    msg = EmailMessage()
    msg["From"] = EMAIL_SENDER
    msg["To"] = recipient
    msg["Subject"] = subject
    msg.set_content(body)

    try:
        ctx = ssl.create_default_context()
        with smtplib.SMTP("smtp.gmail.com", 587) as server:
            server.starttls(context=ctx)
            server.login(EMAIL_SENDER, EMAIL_PASS)
            server.send_message(msg)
        return True, "sent"
    except Exception as e:
        return False, str(e)


# ============= TELEGRAM VIA TELETHON (USER ACCOUNT) =============

TG_API_ID = int(os.getenv("TG_API_ID", "0"))
print(TG_API_ID)
TG_API_HASH = os.getenv("TG_API_HASH")
print(TG_API_HASH)
TG_SESSION_NAME = os.getenv("TG_SESSION_NAME", "telegram_birthday_session")
print(TG_SESSION_NAME)

telegram_client: TelegramClient | None = None


def init_telegram_client():
    global telegram_client
    if telegram_client is None:
        if not TG_API_ID or not TG_API_HASH or TG_API_ID == 0:
            raise RuntimeError("Telegram API ID/HASH not set in environment variables")
        telegram_client = TelegramClient(TG_SESSION_NAME, TG_API_ID, TG_API_HASH)
    return telegram_client


async def _tg_send_dm(username: str, text: str):
    client = init_telegram_client()
    async with client:
        await client.send_message(username, text)


def send_telegram_from_me(username: str, text: str):
    """Send Telegram DM from your own account using Telethon user session."""
    import asyncio
    try:
        asyncio.run(_tg_send_dm(username, text))
        return True, "sent"
    except Exception as e:
        return False, str(e)


# ============= SELENIUM PART: WHATSAPP / IG / SNAP =============


def make_driver():
    """Create a Selenium driver. Adjust if you use a different browser."""
    options = webdriver.ChromeOptions()
    # You can add a user-data-dir here to persist sessions if you like.
    driver = webdriver.Chrome(options=options)
    driver.maximize_window()
    return driver


# --- WhatsApp Web ---

def wa_login(driver):
    driver.get("https://web.whatsapp.com/")
    input("Log into WhatsApp Web in the browser, then press Enter here to continue...")


def wa_send_message(driver, contact_name: str, text: str):
    wait = WebDriverWait(driver, 30)

    search_box = wait.until(
        EC.presence_of_element_located(
            (By.XPATH, "//div[@contenteditable='true' and @data-tab='3']")
        )
    )
    search_box.click()
    search_box.send_keys(Keys.CONTROL, "a")
    search_box.send_keys(Keys.DELETE)
    search_box.send_keys(contact_name)
    time.sleep(2)

    chat = wait.until(
        EC.element_to_be_clickable(
            (By.XPATH, f"//span[@title='{contact_name}']")
        )
    )
    chat.click()

    msg_box = wait.until(
        EC.presence_of_element_located(
            (By.XPATH, "//div[@contenteditable='true' and @data-tab='10']")
        )
    )
    msg_box.click()
    msg_box.send_keys(text)
    msg_box.send_keys(Keys.ENTER)


# --- Instagram Web ---

def ig_login(driver):
    driver.get("https://www.instagram.com/")
    input("Log into Instagram and land on the home page, then press Enter here to continue...")


def ig_send_dm(driver, username: str, text: str):
    wait = WebDriverWait(driver, 30)

    driver.get("https://www.instagram.com/direct/inbox/")

    new_msg_btn = wait.until(
        EC.element_to_be_clickable(
            (By.XPATH, "//div[contains(text(), 'Send message') or contains(@aria-label,'New message')]")
        )
    )
    new_msg_btn.click()

    search_box = wait.until(
        EC.presence_of_element_located(
            (By.XPATH, "//input[@name='queryBox' or @placeholder='Search']")
        )
    )
    search_box.send_keys(username)
    time.sleep(2)

    user_entry = wait.until(
        EC.element_to_be_clickable(
            (By.XPATH, f"//div[text()='{username}']")
        )
    )
    user_entry.click()

    next_btn = wait.until(
        EC.element_to_be_clickable(
            (By.XPATH, "//div[text()='Next']")
        )
    )
    next_btn.click()

    msg_box = wait.until(
        EC.presence_of_element_located(
            (By.XPATH, "//textarea[@placeholder='Message...']")
        )
    )
    msg_box.click()
    msg_box.send_keys(text)
    msg_box.send_keys(Keys.ENTER)


# --- Snapchat Web ---

def sc_login(driver):
    driver.get("https://web.snapchat.com/")
    input("Log into Snapchat Web, then press Enter here to continue...")


def sc_send_chat(driver, username: str, text: str):
    wait = WebDriverWait(driver, 30)

    search_box = wait.until(
        EC.presence_of_element_located(
            (By.XPATH, "//input[@placeholder='Search']")
        )
    )
    search_box.click()
    search_box.send_keys(username)
    time.sleep(2)

    user_entry = wait.until(
        EC.element_to_be_clickable(
            (By.XPATH, f"//div[contains(@aria-label, '{username}')]")
        )
    )
    user_entry.click()

    msg_box = wait.until(
        EC.presence_of_element_located(
            (By.XPATH, "//div[@contenteditable='true']")
        )
    )
    msg_box.click()
    msg_box.send_keys(text)
    msg_box.send_keys(Keys.ENTER)


# ============= ORCHESTRATION =============


def send_wishes_for_contact(
    c: Dict[str, Any],
    today_mm_dd: str,
    drivers: Dict[str, webdriver.Chrome]
):
    if c.get("birthday") != today_mm_dd:
        return

    name = c["name"]
    msg = personalize(name)
    print(f"\n=== Sending to {name} ===")

    platforms = c.get("platforms", [])

    # # Email
    # if "email" in platforms and c.get("email"):
    #     ok, info = send_email(c["email"], c["subject"], msg)
    #     print("Email:", "OK" if ok else "FAIL", info)

    # # SMS via Twilio
    # if "sms" in platforms and c.get("phone"):
    #     ok, info = send_sms(c["phone"], msg)
    #     print("SMS:", "OK" if ok else "FAIL", info)

    # # Telegram from your own account via Telethon
    # if "telegram" in platforms and c.get("telegram_username"):
    #     ok, info = send_telegram_from_me(c["telegram_username"], msg)
    #     print("Telegram:", "OK" if ok else "FAIL", info)

    # # Selenium platforms
    if "whatsapp" in platforms and c.get("whatsapp_name"):
        driver = drivers.setdefault("whatsapp", make_driver())
        if not drivers.get("whatsapp_initialized"):
            wa_login(driver)
            drivers["whatsapp_initialized"] = True
        try:
            wa_send_message(driver, c["whatsapp_name"], msg)
            print("WhatsApp: OK")
        except Exception as e:
            print("WhatsApp: FAIL", e)

    # if "instagram" in platforms and c.get("instagram_username"):
    #     driver = drivers.setdefault("instagram", make_driver())
    #     if not drivers.get("instagram_initialized"):
    #         ig_login(driver)
    #         drivers["instagram_initialized"] = True
    #     try:
    #         ig_send_dm(driver, c["instagram_username"], msg)
    #         print("Instagram: OK")
    #     except Exception as e:
    #         print("Instagram: FAIL", e)

    # if "snapchat" in platforms and c.get("snapchat_username"):
    #     driver = drivers.setdefault("snapchat", make_driver())
    #     if not drivers.get("snapchat_initialized"):
    #         sc_login(driver)
    #         drivers["snapchat_initialized"] = True
    #     try:
    #         sc_send_chat(driver, c["snapchat_username"], msg)
    #         print("Snapchat: OK")
    #     except Exception as e:
    #         print("Snapchat: FAIL", e)


def main():
    today_mm_dd = datetime.now().strftime("%m-%d")
    drivers: Dict[str, webdriver.Chrome] = {}

    try:
        for c in CONTACTS:
            send_wishes_for_contact(c, today_mm_dd, drivers)
    finally:
        for key, drv in list(drivers.items()):
            if isinstance(drv, webdriver.Chrome):
                drv.quit()


if __name__ == "__main__":
    main()
