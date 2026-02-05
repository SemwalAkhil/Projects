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

def wa_login(driver):
    driver.get("https://web.whatsapp.com/")
    wait = WebDriverWait(driver,10)
    loginLink = wait.until(
        EC.presence_of_element_located(
            (By.XPATH,"//div[contains(text(), 'Log in with phone number')]")
        )
    )
    loginLink.click()
    countries = ["United States", "India",
    "Afghanistan", "Albania", "Algeria", "American Samoa", "Andorra", "Angola",
    "Anguilla", "Antigua & Barbuda", "Argentina", "Armenia", "Aruba", "Australia",
    "Austria", "Azerbaijan", "Bahamas", "Bahrain", "Bangladesh", "Barbados",
    "Belarus", "Belgium", "Belize", "Benin", "Bermuda", "Bhutan", "Bolivia",
    "Bosnia & Herzegovina", "Botswana", "Brazil", "British Indian Ocean Territory",
    "British Virgin Islands", "Brunei", "Bulgaria", "Burkina Faso", "Burundi",
    "Cambodia", "Cameroon", "Canada", "Cape Verde", "Cayman Islands",
    "Central African Republic", "Chad", "Chile", "China", "Colombia", "Comoros",
    "Congo, Democratic Republic", "Congo, Republic", "Cook Islands", "Costa Rica",
    "Croatia", "Cuba", "Curaçao", "Cyprus", "Czech Republic", "Denmark", "Djibouti",
    "Dominica", "Dominican Republic", "Ecuador", "Egypt", "El Salvador",
    "Equatorial Guinea", "Eritrea", "Estonia", "Eswatini", "Ethiopia", "Fiji",
    "Finland", "France", "French Guiana", "French Polynesia", "Gabon", "Gambia",
    "Georgia", "Germany", "Ghana", "Gibraltar", "Greece", "Greenland", "Grenada",
    "Guadeloupe", "Guam", "Guatemala", "Guinea", "Guinea-Bissau", "Guyana", "Haiti",
    "Honduras", "Hong Kong", "Hungary", "Iceland", "Indonesia", "Iran",
    "Iraq", "Ireland", "Isle of Man", "Israel", "Italy", "Ivory Coast", "Jamaica",
    "Japan", "Jordan", "Kazakhstan", "Kenya", "Kiribati", "Kuwait", "Kyrgyzstan",
    "Laos", "Latvia", "Lebanon", "Lesotho", "Liberia", "Libya", "Liechtenstein",
    "Lithuania", "Luxembourg", "Macau", "Madagascar", "Malawi", "Malaysia",
    "Maldives", "Mali", "Malta", "Marshall Islands", "Martinique", "Mauritania",
    "Mauritius", "Mayotte", "Mexico", "Micronesia", "Moldova", "Monaco", "Mongolia",
    "Montenegro", "Montserrat", "Morocco", "Mozambique", "Myanmar", "Namibia",
    "Nauru", "Nepal", "Netherlands", "New Caledonia", "New Zealand", "Nicaragua",
    "Niger", "Nigeria", "North Korea", "North Macedonia", "Northern Mariana Islands",
    "Norway", "Oman", "Pakistan", "Palau", "Palestine", "Panama",
    "Papua New Guinea", "Paraguay", "Peru", "Philippines", "Poland", "Portugal",
    "Puerto Rico", "Qatar", "Réunion", "Romania", "Russia", "Rwanda", "Samoa",
    "San Marino", "São Tomé & Príncipe", "Saudi Arabia", "Senegal", "Serbia",
    "Seychelles", "Sierra Leone", "Singapore", "Sint Maarten", "Slovakia",
    "Slovenia", "Solomon Islands", "Somalia", "South Africa", "South Korea",
    "South Sudan", "Spain", "Sri Lanka", "St. Kitts & Nevis", "St. Lucia",
    "St. Vincent & Grenadines", "Sudan", "Suriname", "Sweden", "Switzerland",
    "Syria", "Taiwan", "Tajikistan", "Tanzania", "Thailand", "Timor-Leste", "Togo",
    "Tonga", "Trinidad & Tobago", "Tunisia", "Turkey", "Turkmenistan",
    "Turks & Caicos Islands", "Tuvalu", "Uganda", "Ukraine", "United Arab Emirates",
    "United Kingdom", "Uruguay", "Uzbekistan", "Vanuatu",
    "Vatican City", "Venezuela", "Vietnam", "Virgin Islands (U.S.)", "Yemen",
    "Zambia", "Zimbabwe"
]

    # countryCode = wait.until(
    #     EC.presence_of_element_located(
    #         (By.XPATH, "//span[contains(text(),'India') or contains(text(),'United States')]")
    #     )
    # )
    for i,j in enumerate(countries):
        print(f"Trying {j}")
        try:
            element = wait.until(
                EC.element_to_be_clickable((By.XPATH, f"//span[contains(text(),{j})]"))
            )
            break
        except:
            pass
    if i < (len(countries) - 1):
        driver.execute_script("arguments[0].scrollIntoView();", element)

    
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

def make_driver():
    """Create a Selenium driver. Adjust if you use a different browser."""
    options = webdriver.ChromeOptions()
    # You can add a user-data-dir here to persist sessions if you like.
    driver = webdriver.Chrome(options=options)
    driver.maximize_window()
    return driver

def main(c: Dict[str, Any], drivers: Dict[str, webdriver.Chrome], msg: str):
    driver = drivers.setdefault("whatsapp", make_driver())
    if not drivers.get("whatsapp_initialized"):
        wa_login(driver)
        drivers["whatsapp_initialized"] = True
    try:
        wa_send_message(driver, c["whatsapp_name"], msg)
        print("WhatsApp: OK")
    except Exception as e:
        print("WhatsApp: FAIL", e)

if __name__ == "__main__":
    drivers: Dict[str, webdriver.Chrome] = {}
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
    
    main(CONTACTS[0],drivers,"hello")
