// 9. How to convert String to Date

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;

class StringToDate {
    public static void main(String[] args) {
        String dateStr = "2025-10-17"; 

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");

        try {
            LocalDate date = LocalDate.parse(dateStr, formatter);
            System.out.println("Converted Date: " + date);
        } catch (DateTimeParseException e) {
            System.out.println("Invalid date format: " + dateStr);
        }
    }
}

/*
 Output:
Converted Date: 2025-10-17
 */