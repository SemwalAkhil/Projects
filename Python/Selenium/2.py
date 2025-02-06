# ANIMEPAHE SCRAPPER I
import os
import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from bs4 import BeautifulSoup
from threading import Thread

def wait_for_download(folder_path, file_name, timeout=3600):
    """
    Wait for a file to appear in the specified folder.

    :param folder_path: Path to the download folder.
    :param file_name: Expected file name.
    :param timeout: Maximum wait time in seconds.
    :return: True if the file is downloaded, False if timeout is reached.
    """
    start_time = time.time()
    while True:
        files = os.listdir(folder_path)
        if file_name in files or any(file.endswith(".mp4") for file in files):
            print(f"{file_name} download completed.")
            return True
        elif time.time() - start_time > timeout:
            print(f"Timeout reached. {file_name} not found.")
            return False
        time.sleep(1)  # Wait a bit before checking again

def setup_driver(adblocker_path, download_folder):
    prefs = {
        "download.default_directory": os.path.join(os.getcwd(), download_folder),
        "download.prompt_for_download": False,
        "download.directory_upgrade": True,
        "safebrowsing.enabled": True
    }
    options = Options()
    options.add_extension(adblocker_path)
    options.add_experimental_option("prefs", prefs)
    return webdriver.Chrome(options=options)

def search_anime(driver, search_query):
    search_bar = WebDriverWait(driver, 100).until(
        EC.presence_of_element_located((By.CLASS_NAME, "input-search"))
    )
    search_bar.send_keys(search_query)
    WebDriverWait(driver, 100).until(
        EC.presence_of_element_located((By.CLASS_NAME, "search-results"))
    )
    results = driver.find_element(By.CLASS_NAME, "search-results").find_elements(By.TAG_NAME, "a")
    for i, result in enumerate(results):
        print(f"{i} > {result.text}")
    return results

def select_episode(driver):
    WebDriverWait(driver, 100).until(
        EC.presence_of_element_located((By.CLASS_NAME, "episode"))
    )
    return driver.find_elements(By.CLASS_NAME, "episode")

def download_episode(driver, quality_index):
    
    html = driver.page_source
    soup = BeautifulSoup(html, "html.parser")
    qualities = soup.find(id="pickDownload").find_all("a")

    selected_quality = qualities[quality_index]
    driver.get(selected_quality.get("href"))
    main_window = driver.current_window_handle

    try:
        btn = WebDriverWait(driver, 100).until(
            EC.presence_of_element_located((By.CLASS_NAME, "redirect"))
        )
        while "Continue" not in btn.text:
            pass
        link = btn.get_attribute("href")
        driver.switch_to.new_window('tab')
        driver.get(link)
        download_btn = WebDriverWait(driver, 100).until(
            EC.presence_of_element_located((By.TAG_NAME, "button"))
        )
        file_name_elem = WebDriverWait(driver, 100).until(
            EC.presence_of_element_located((By.TAG_NAME, "h1"))
        )
        file_name = file_name_elem.text
        download_btn.click()
        driver.close()
        driver.switch_to.window(main_window)
        driver.back()
        driver.back()
        return file_name
    except Exception as e:
        print(f"Error during download: {e}")
        return None

def handle_episode_download(url, quality_index, download_folder):
    options = Options()
    prefs = {"download.default_directory": os.path.join(os.getcwd(), download_folder)}
    options.add_experimental_option("prefs", prefs)
    driver = webdriver.Chrome(options=options)
    driver.get(url)

    file_name = download_episode(driver, quality_index)
    if file_name:
        wait_for_download(download_folder, file_name)
    else:
        print(f"Error downloading from URL: {url}")
    driver.quit()

def get_episode_links(driver):
    episodes = WebDriverWait(driver, 100).until(
        EC.presence_of_all_elements_located((By.CLASS_NAME, "episode"))
    )
    return [episode.get_attribute("href") for episode in episodes]


def main():
    adblocker = r"D:\\Projects\\Python\\Selenium\\ublock.crx"
    download_folder = "DownloadedAnime"

    try:
        os.mkdir(download_folder)
        print(f"Folder created: {download_folder}")
    except FileExistsError:
        print(f"Folder already exists: {download_folder}\nSkipping creation.")
    except Exception as e:
        print(f"An error occurred: {e}")
        return

    driver = setup_driver(adblocker, download_folder)
    url = "https://animepahe.ru/"
    driver.get(url)

    search_query = input("Enter anime to search: ")
    search_results = search_anime(driver, search_query)

    anime_index = int(input("Choose anime to download: "))
    search_results[anime_index].click()

    episodes = select_episode(driver)

    episode_links = get_episode_links(driver)
    for i, link in enumerate(episode_links):
        print(f"Downloading episode {i + 1}...")
        thread = Thread(target=handle_episode_download, args=(link, quality_index, download_folder))
        threads.append(thread)
        thread.start()

    for i in range(len(episodes)):
        print(f"Downloading episode {i+1}...")
        episodes[i].click()
        html = driver.page_source
        soup = BeautifulSoup(html, "html.parser")
        qualities = soup.find(id="pickDownload")
        threads = []
        if i == 0:
            if qualities != None:
                qualities = qualities.find_all("a")
            else:
                print("Qualities not found\nDownload Failed")
                driver.quit()
                exit(1)
            for j, quality in enumerate(qualities):
                print(f"{j} > {quality.text}")
            quality_index = int(input("Choose quality to download: "))
        thread = Thread(target=handle_episode_download, args=(driver, quality_index, download_folder))
        threads.append(thread)
        thread.start()
        episodes = select_episode(driver)

    for thread in threads:
        thread.join()

    print("Download completed. Exiting browser...")
    driver.quit()

if __name__ == "__main__":
    main()
