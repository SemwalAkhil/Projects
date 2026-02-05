# ANIMEPAHE SCRAPPER (WITH THREADING)
import os
import time
import signal
import sys
import selenium.webdriver
from selenium import webdriver
from selenium.webdriver.common.by import By

from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from bs4 import BeautifulSoup
from threading import Thread, Semaphore
from selenium.common.exceptions import StaleElementReferenceException

DRIVER = webdriver.Firefox

# Semaphore to limit parallel downloads
MAX_PARALLEL_DOWNLOADS = 3
semaphore = Semaphore(MAX_PARALLEL_DOWNLOADS)
threads = []

# Graceful shutdown flag
terminate_flag = False

def signal_handler(sig, frame):
    global terminate_flag
    print("\nTermination signal received. Cleaning up...")
    terminate_flag = True

# Register signal handler for graceful termination
signal.signal(signal.SIGINT, signal_handler)

def wait_for_download(folder_path:str, file_name:str, timeout:float=3600):
    """
    Wait for a file to appear in the specified folder.

    :param folder_path: Path to the download folder.
    :param file_name: Expected file name.
    :param timeout: Maximum wait time in seconds.
    :return: True if the file is downloaded, False if timeout is reached.
    """
    start_time = time.time()
    while True:
        if terminate_flag:
            return False
        files = os.listdir(folder_path)
        if file_name in files:
            print(f"{file_name} download completed.")
            return True
        elif time.time() - start_time > timeout:
            print(f"Timeout reached. {file_name} not found.")
            return False
        time.sleep(1)  # Wait a bit before checking again

def setup_driver(download_folder:str="", adblocker_path:str="", headless:bool=False, disableGPU:bool=True, noSandbox:bool=True, logLevel3:bool=True, disableSoftwareRasterizer:bool=True,disableWebGL:bool=True)->webdriver.Chrome | webdriver.Firefox | None:
    prefs = {
        "download.default_directory": os.path.join(os.getcwd(), download_folder),
        "download.prompt_for_download": False,
        "download.directory_upgrade": True,
        "safebrowsing.enabled": True
    }
    if DRIVER == webdriver.Firefox:
        from selenium.webdriver.firefox.options import Options
        options = Options()
    elif DRIVER == webdriver.Chrome:
        from selenium.webdriver.chrome.options import Options
        options = Options()
    
    if headless:
        options.add_argument("--headless")  # Run browser in headless mode
    if disableGPU:
        options.add_argument("--disable-gpu")  # Disable GPU usage (optional, for compatibility)
    if noSandbox:
        options.add_argument("--no-sandbox")  # Disable sandbox (useful in some environments)
    if logLevel3:
        options.add_argument("--log-level=3")  # Reduce logging output
    if disableSoftwareRasterizer:
        options.add_argument("--disable-software-rasterizer")  # Prevents software rendering
    if disableWebGL:
        options.add_argument("--disable-webgl")  # Disables WebGL rendering
    if adblocker_path != "":
        if type(options) == webdriver.ChromeOptions:
            options.add_extension(adblocker_path)
            return webdriver.Chrome(options=options)
        
        elif type(options) == webdriver.FirefoxOptions:
            driver = webdriver.Firefox(options=options) 
            driver.install_addon(adblocker_path)
            return driver 
        
        else:
            return None
    

def search_anime(driver:webdriver.Chrome | webdriver.Firefox, search_query:str):
    search = True
    count = 0
    maxTry = 5
    while search and count < maxTry:
        count += 1
        try:
            search_bar = WebDriverWait(driver, 100).until(
                EC.presence_of_element_located((By.CLASS_NAME, "input-search"))
            )
            search_bar.send_keys(search_query)
            WebDriverWait(driver, 100).until(
                EC.presence_of_element_located((By.CLASS_NAME, "search-results"))
            )
            results = driver.find_element(By.CLASS_NAME, "search-results").find_elements(By.TAG_NAME, "a")
            search = False
        except Exception as e:
            print(f"SEARCH FAILED: RETRYING {count}/{maxTry}")
            if count == 1:
                with open("error.txt","w",encoding="utf-8") as err:
                    err.write("\n======================================================================\n")
                    err.write(str(e))
                    err.write("\n======================================================================\n")
                    err.write(driver.page_source)
                    err.write("\n======================================================================\n")
            else:
                with open("error.txt","w",encoding="utf-8") as err:
                    err.write("\n======================================================================\n")
                    err.write(str(e))
                    err.write("\n======================================================================\n")
                    err.write(driver.page_source)
                    err.write("\n======================================================================\n")
            # print(driver.page_source)
            driver.refresh()
            time.sleep(5)
    if count == maxTry:
        print("MAX TRY REACHED: EXITING PROGRAM!")
        driver.quit()
        exit()
    else:
        for i, result in enumerate(results):
            print(f"{i} > {result.text}")
        return results

def get_episode_links(driver:webdriver.Chrome | webdriver.Firefox):
    WebDriverWait(driver, 100).until(
        EC.presence_of_element_located((By.CLASS_NAME, "episode"))
    )
    episodes = driver.find_elements(By.CLASS_NAME, "play")
    return [episode.get_attribute("href") for episode in episodes]

def download_episode(driver:webdriver.Chrome | webdriver.Firefox, quality_index:int):
    if terminate_flag:
        return None
    try:
        WebDriverWait(driver,100).until(
            EC.presence_of_element_located((By.ID,"pickDownload"))
        )
    except:
        print("Download Failed")
        exit(1)
    html = driver.page_source
    soup = BeautifulSoup(html, "html.parser")
    try:
        qualities = soup.find(id="pickDownload").find_all("a")
    except:
        print("Qualities not found")
        exit(1)

    selected_quality = qualities[quality_index]

    # Extract file size and convert it to an integer (in MB)
    size_text = selected_quality.text.split("(")[1].split("MB")[0].strip()
    try:
        total_size = int(size_text)
    except ValueError:
        total_size = 0
    lnk = selected_quality.get("href")
    if type(lnk) == str:
        driver.get(lnk)
    else:
        driver.get("")
    main_window = driver.current_window_handle

    try:
        btn = WebDriverWait(driver, 100).until(
            EC.presence_of_element_located((By.CLASS_NAME, "redirect"))
        )
        while "Continue" not in btn.text:
            if terminate_flag:
                return None
            pass
        link = btn.get_attribute("href")
        driver.switch_to.new_window('tab')
        if type(link) == str:
            driver.get(link)
        else:
            driver.get("")
        download_btn = WebDriverWait(driver, 100).until(
            EC.presence_of_element_located((By.TAG_NAME, "button"))
        )
        file_name_elem = WebDriverWait(driver, 100).until(
            EC.presence_of_element_located((By.TAG_NAME, "h1"))
        )
        file_name = file_name_elem.text

        # Simulated progress bar based on file size
        print(f"Downloading {file_name} ({total_size} MB)...")
        for i in range(1, 101):
            if terminate_flag:
                print("Download interrupted.")
                return None
            time.sleep(total_size / 100)  # Simulate download progress proportionally
            print(f"\rProgress of {file_name} : {i}%",end="\r")

        download_btn.click()
        driver.close()
        driver.switch_to.window(main_window)
        return file_name
    except Exception as e:
        print(f"Error during download: {e}")
        return None

def handle_episode_download(adblocker_path:str, url:str, quality_index:int, download_folder:str, count:int):
    global semaphore
    with semaphore:
        driver = setup_driver(adblocker_path,download_folder)
        if terminate_flag:
            print(f"Thread {count+1} terminated before starting download.")
            return
        # print(f"Thread {count+1} working...")
        if not driver:
            exit()
        driver.get(url)

        file_name = download_episode(driver, quality_index)
        if file_name:
            wait_for_download(download_folder, file_name)
        else:
            print(f"Error downloading from URL: {url}")
        driver.quit()

def main():
    global threads
    # adblocker = r"D:\\Projects\\Python\\Selenium\\ublock.crx" # chrome
    adblocker = r"D:\Projects\Python\Selenium\ublock_origin-1.68.0.xpi"
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
    if not driver:
        print("DRIVER NOT INITIALISED: EXITING!")
        exit()

    url = "https://animepahe.si/"
    driver.get(url)

    search_query = input("Enter anime to search: ")
    search_results = search_anime(driver, search_query)

    anime_index = int(input("Choose anime to download: "))
    search_results[anime_index].click()

    episode_links = get_episode_links(driver)

    for i, link in enumerate(episode_links):
        if terminate_flag:
            print("Termination in progress. Skipping episodes.")
            break
        print(f"Downloading episode {i + 1}...")
        if link:
            driver.get(link)
        else:
            print("Link Not Found")
            continue
        if i == 0:
            if terminate_flag:
                print("Termination in progress. Skipping episodes.")
                break
            html = driver.page_source
            soup = BeautifulSoup(html, "html.parser")
            qualities = soup.find(id="pickDownload")
            try:
                qualities = soup.find(id="pickDownload")
                qualities = qualities.find_all("a")
            except:
                print("Qualities not found\nDownload Failed")
                driver.quit()
                exit(1)
            for j, quality in enumerate(qualities):
                print(f"{j} > {quality.text}")
            quality_index = int(input("Choose quality to download: "))
        thread = Thread(target=handle_episode_download, args=(adblocker, link, quality_index, download_folder, i))
        threads.append(thread)
        thread.start()

    for thread in threads:
        if thread.is_alive():
            thread.join()

    print("Download completed. Exiting browser...")
    driver.quit()

if __name__ == "__main__":
    main()
