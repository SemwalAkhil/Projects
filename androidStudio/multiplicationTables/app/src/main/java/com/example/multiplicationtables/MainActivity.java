package com.example.multiplicationtables;

import android.content.Context;
import android.content.res.Resources;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.TypedValue;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewTreeObserver;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    public TableLayout tableLayout;
    public TableRow tableRow;
    public LayoutInflater layoutInflater;
    public EditText editText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        tableLayout = findViewById(R.id.tableLayout);
        editText = findViewById(R.id.editTextNumber);
        editText.addTextChangedListener(new TextWatcher(){
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }
            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

            }
            @Override
            public void afterTextChanged(Editable s) {
                if (s.length() != 0) {
                    tableLayout.removeAllViews();
                    createTable(tableLayout, Integer.parseInt(editText.getText().toString()));
                }
            }
        });
    }

    public static int dpToPx(int dp) {
        Resources r = Resources.getSystem();
        return (int) TypedValue.applyDimension(
                TypedValue.COMPLEX_UNIT_DIP,
                dp,
                r.getDisplayMetrics()
        );
    }
    private void createTable(TableLayout tableLayout, int num) {
        Context context = tableLayout.getContext(); // Get context from TableLayout

        for (int i = 1 ; i <= 10 ; i++) {
            TableRow tableRow = new TableRow(context);
            TextView textView = new TextView(context);
            textView.setText(String.format("%d x %d = %d", num, i, num * i));
//            String.format() internally uses a StringBuilder to construct the final string, which avoids the overhead of creating               multiple intermediate string objects. This leads to better performance, especially when dealing with a large number of             concatenations.
//            textView.setText(num + " x " + i + " = " + (num * i));
            textView.setGravity(Gravity.CENTER);
            textView.setHeight(dpToPx(47));
            tableRow.setGravity(Gravity.CENTER);
            tableRow.addView(textView);
            tableLayout.addView(tableRow);
        }
    }
}