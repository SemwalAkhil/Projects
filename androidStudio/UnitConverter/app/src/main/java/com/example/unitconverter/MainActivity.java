package com.example.unitconverter;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {
    private EditText editText;
    private TextView textView;
    private double weight1;
    private double weight2;

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
        Button button = findViewById(R.id.button);
        editText = findViewById(R.id.editTextNumberDecimal);
        textView = findViewById(R.id.textView);
        Spinner spinner1 = findViewById(R.id.spinner);
        Spinner spinner2 = findViewById(R.id.spinner2);
        // Create an array of options
        String[] options = {"Kilograms", "Grams", "Pounds","Ounces"};

        // Create an ArrayAdapter to bind the options to the spinner
        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, options);

        // Set the adapter to the spinner
        spinner1.setAdapter(adapter);
        spinner2.setAdapter(adapter);
//        conversion using "onclick listener"
//        button.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View view) {
//                  String input = editText.getText().toString();
//                  if (input.isEmpty()) {
//                      Toast.makeText(MainActivity.this, "Please enter a number", Toast.LENGTH_SHORT).show();
//                      return;
//                   }
//                  double number = Integer.parseInt(input) * weight1 * weight2;
//                  textView.setText(String.valueOf(number));
////                Toast.makeText(MainActivity.this, "You entered: " + input, Toast.LENGTH_SHORT).show();
////                Toast.makeText(MainActivity.this, "Weights: " + weight1 + " ," + weight2, Toast.LENGTH_SHORT).show();
//            }
//        });
        spinner1.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                // Get the selected item
                String selectedItem = (String) parent.getItemAtPosition(position);
                if (position == 0){
                    weight1 = 1;
                } else if ( position == 1) {
                    weight1 = 0.001;
                } else if (position == 2) {
                    weight1 = 0.453592;
                } else if (position == 3) {
                    weight1 = 0.0283495;
                }
//                Toast.makeText(MainActivity.this, "Selected item: " + selectedItem, Toast.LENGTH_SHORT).show();
//                Toast.makeText(MainActivity.this, "Selected weight1: " + weight1, Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
                // Do something when nothing is selected

            }
        });
        spinner2.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                // Get the selected item
                String selectedItem = (String) parent.getItemAtPosition(position);
                if (position==0){
                    weight2 = 1;
                } else if ( position == 1) {
                    weight2 = 1000;
                } else if ( position == 2) {
                    weight2 = 2.20462;
                } else if ( position == 3) {
                    weight2 = 35.274;
                }
//                Toast.makeText(MainActivity.this, "Selected item: " + selectedItem, Toast.LENGTH_SHORT).show();
//                Toast.makeText(MainActivity.this, "Weight2: " + weight2, Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
                // Do something when nothing is selected

            }
        });
    }

//    using button attribute "onclick" in xml
    public void convert(View view) {
        String input = editText.getText().toString();
        if (input.isEmpty()) {
            Toast.makeText(MainActivity.this, "Please enter a number", Toast.LENGTH_SHORT).show();
            return;
        }
        float number =
                Float.parseFloat(input) * (float) weight1 * (float) weight2;
        textView.setText(String.valueOf(number));
    }
}