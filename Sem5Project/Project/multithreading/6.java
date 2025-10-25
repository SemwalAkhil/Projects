// 6. Write a Java program to implement a concurrent web crawler that crawls multiple websites simultaneously using threads.

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;

class WebCrawlerThread extends Thread {
    private String website;

    WebCrawlerThread(String website) {
        this.website = website;
    }

    public void run() {
        System.out.println("Crawling: " + website);
        try {
            URL url = new URL(website);
            BufferedReader in = new BufferedReader(new InputStreamReader(url.openStream()));
            int lines = 0;
            while (in.readLine() != null) {
                lines++;
            }
            in.close();
            System.out.println(website + " has " + lines + " lines of HTML.");
        } catch (Exception e) {
            System.out.println("Failed to crawl: " + website);
            e.printStackTrace();
        }
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        String[] websites = {
            "https://www.example.com",
            "https://www.wikipedia.org",
            "https://www.openai.com"
        };

        Thread[] threads = new Thread[websites.length];

        for (int i = 0; i < websites.length; i++) {
            threads[i] = new WebCrawlerThread(websites[i]);
            threads[i].start();
        }

        for (int i = 0; i < websites.length; i++) {
            threads[i].join();
        }

        System.out.println("Web crawling completed.");
    }
}

/*
Output :
Crawling: https://www.example.com
Crawling: https://www.wikipedia.org
Crawling: https://www.openai.com
https://www.example.com has 14 lines of HTML.
https://www.wikipedia.org has 213 lines of HTML.
https://www.openai.com has 87 lines of HTML.
Web crawling completed.
*/
