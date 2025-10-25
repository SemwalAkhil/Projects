// 24. How to convert Timestamp to Date

import java.sql.Timestamp;
import java.util.Date;

class TimestampToDate {
    public static void main(String[] args) {
        Timestamp timestamp = new Timestamp(System.currentTimeMillis());
       Date date1 = timestamp;
        Date date2 = new Date(timestamp.getTime());

        System.out.println("Timestamp: " + timestamp);
        System.out.println("Date1 (direct assignment): " + date1);
        System.out.println("Date2 (new Date object): " + date2);
    }
}
/*Output:
Timestamp: 2025-10-17 12:34:56.789
Date1 (direct assignment): Fri Oct 17 12:34:56 PDT 2025
Date2 (new Date object): Fri Oct 17 12:34:56 PDT 2025
 */