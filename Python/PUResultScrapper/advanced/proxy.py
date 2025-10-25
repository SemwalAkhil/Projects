import requests
from bs4 import BeautifulSoup
from random import shuffle

class ProxyFetcher:
    def __init__(self, test_url="http://httpbin.org/ip", timeout=5):
        self.source_url = "https://free-proxy-list.net/en/"
        self.test_url = test_url
        self.timeout = timeout
        self.working_proxies = []

    def fetch_raw_proxies(self):
        print("[*] Fetching proxies...")
        response = requests.get(self.source_url)
        soup = BeautifulSoup(response.text, 'html.parser')
        proxy_table = soup.find("table")

        proxies = []
        if not proxy_table:
            print("[!] Proxy table not found.")
            return proxies

        for row in proxy_table.tbody.find_all("tr"):
            cols = row.find_all("td")
            ip = cols[0].text.strip()
            port = cols[1].text.strip()
            https = cols[6].text.strip().lower() == "yes"
            anonymous = cols[4].text.strip().lower() == "anonymous"
            if not https or not anonymous:
                continue
            proxy = f"http{'s' if https else ''}://{ip}:{port}"
            proxies.append(proxy)

        print(f"[*] Found {len(proxies)} proxies")
        shuffle(proxies)
        return proxies

    def test_proxy(self, proxy):
        try:
            response = requests.get(self.test_url, proxies={"http": proxy, "https": proxy}, timeout=self.timeout)
            if response.status_code == 200:
                return True
        except:
            pass
        return False

    def get_working_proxies(self, max_proxies=10):
        raw_proxies = self.fetch_raw_proxies()
        print("[*] Testing proxies...")
        self.working_proxies = []

        for proxy in raw_proxies:
            if self.test_proxy(proxy):
                print(f"[+] Working proxy: {proxy}")
                self.working_proxies.append(proxy)
                if len(self.working_proxies) >= max_proxies:
                    break

        print(f"[✓] Total working proxies: {len(self.working_proxies)}")
        return self.working_proxies

if __name__ == "__main__":
    pf = ProxyFetcher()
    working_proxies = pf.get_working_proxies(max_proxies=5)
    print(working_proxies)