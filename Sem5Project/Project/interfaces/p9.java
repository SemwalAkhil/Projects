// 9. Write a Java program to create an interface Searchable with a method search(String keyword) that searches for a given keyword in a text document. Create two classes Document and WebPage that implement the Searchable interface and provide their own implementations of the search() method.

interface Searchable {
    void search(String keyword);
}

class Document implements Searchable {
    String text;

    Document(String text) {
        this.text = text;
    }

    public void search(String keyword) {
        if(text.contains(keyword)) System.out.println("Keyword found in Document");
        else System.out.println("Keyword not found in Document");
    }
}

class WebPage implements Searchable {
    String html;

    WebPage(String html) {
        this.html = html;
    }

    public void search(String keyword) {
        if(html.contains(keyword)) System.out.println("Keyword found in WebPage");
        else System.out.println("Keyword not found in WebPage");
    }
}

public class Main {
    public static void main(String[] args) {
        Searchable doc = new Document("This is a sample document about Java programming.");
        Searchable page = new WebPage("<html><body>Learn Java online</body></html>");

        doc.search("Java");
        page.search("Python");
    }
}

/*
Output:
Keyword found in Document
Keyword not found in WebPage
*/
