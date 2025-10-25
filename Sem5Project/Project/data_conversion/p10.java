// 10. How to convert Date to String

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

class DateToStr {
    public static void main(String[] args) {
        LocalDate date = LocalDate.of(2025, 10, 17);

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");

        String formattedDate = date.format(formatter);

        System.out.println("Formatted Date: " + formattedDate);
    }
}

/*
 Output:
Formatted Date: 17-10-2025

 */