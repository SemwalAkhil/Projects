package com.example.diceroller2

import android.os.Bundle
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import kotlin.random.Random

class MainActivity : AppCompatActivity() {
    private lateinit var diceImage : ImageView
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
        diceImage = findViewById(com.example.diceroller2.R.id.dice_image)
        val rollButton:Button = findViewById(R.id.roll_button)
//        rollButton.text = "let's roll" // dynamic modifications
        rollButton.setOnClickListener {
//            Toast.makeText(this,"Button Clicked",Toast.LENGTH_SHORT).show()
            rollDice()
        }
    }

    private fun rollDice() {
//        val resultText:TextView = findViewById(R.id.name_text)
//        val num = Random.nextInt(6) + 1
//        resultText.text = num.toString()
        val drawableResource = when(Random.nextInt(6) + 1){
            1->R.drawable.dice_1
            2->R.drawable.dice_2
            3->R.drawable.dice_3
            4->R.drawable.dice_4
            5->R.drawable.dice_5
            else->R.drawable.dice_6
        }

//        val diceImage : ImageView = findViewById(R.id.dice_image) // less efficient as findview called each time roll function called
        diceImage.setImageResource(drawableResource)
    }
}