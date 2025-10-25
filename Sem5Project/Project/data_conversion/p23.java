// 23. How to convert Date to Timestamp

import java.sql.Timestamp;
import java.util.Date;

class DateToTimestamp {
    public static void main(String[] args) {
     
        Date date = new Date();
        Timestamp timestamp = new Timestamp(date.getTime());

        System.out.println("Date: " + date);
        System.out.println("Timestamp: " + timestamp);
    }
}

/*Output:
Date: Fri Oct 17 12:34:56 PDT 2025
Timestamp: 2025-10-17 12:34:56.789
 */