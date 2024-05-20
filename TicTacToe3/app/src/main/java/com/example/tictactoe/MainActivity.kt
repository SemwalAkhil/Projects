package com.example.tictactoe

import android.os.Build
import android.os.Bundle
import android.widget.Button
import android.widget.Toast
import androidx.annotation.RequiresApi
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {

    private lateinit var buttons: Array<Array<Button>>
    private var playerXTurn = true
    private var roundCount = 0

    @RequiresApi(Build.VERSION_CODES.M)
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        buttons = arrayOf(
            arrayOf(findViewById(R.id.button00), findViewById(R.id.button01), findViewById(R.id.button02)),
            arrayOf(findViewById(R.id.button10), findViewById(R.id.button11), findViewById(R.id.button12)),
            arrayOf(findViewById(R.id.button20), findViewById(R.id.button21), findViewById(R.id.button22))
        )

        for (i in buttons.indices) {
            for (j in buttons[i].indices) {
                buttons[i][j].setOnClickListener { onButtonClick(buttons[i][j]) }
            }
        }

        findViewById<Button>(R.id.resetButton).setOnClickListener {
            resetGame()
        }
    }

    @RequiresApi(Build.VERSION_CODES.M)
    private fun onButtonClick(button: Button) {
        if (button.text.isNotEmpty()) {
            return
        }

        button.text = if (playerXTurn) "X" else "O"
        button.setTextColor(getColor(if (playerXTurn) R.color.colorButtonX else R.color.colorButtonO))

        roundCount++

        if (checkForWin()) {
            showToast(if (playerXTurn) "Player X wins!" else "Player O wins!")
            resetBoard()
        } else if (roundCount == 9) {
            showToast("Draw!")
            resetBoard()
        } else {
            playerXTurn = !playerXTurn
        }
    }

    private fun checkForWin(): Boolean {
        val field = Array(3) { r ->
            Array(3) { c ->
                buttons[r][c].text.toString()
            }
        }

        // Check rows
        for (i in 0..2) {
            if (field[i][0] == field[i][1] && field[i][0] == field[i][2] && field[i][0].isNotEmpty()) {
                return true
            }
        }

        // Check columns
        for (i in 0..2) {
            if (field[0][i] == field[1][i] && field[0][i] == field[2][i] && field[0][i].isNotEmpty()) {
                return true
            }
        }

        // Check diagonals
        if (field[0][0] == field[1][1] && field[0][0] == field[2][2] && field[0][0].isNotEmpty()) {
            return true
        }
        if (field[0][2] == field[1][1] && field[0][2] == field[2][0] && field[0][2].isNotEmpty()) {
            return true
        }

        return false
    }

    private fun resetBoard() {
        for (i in buttons.indices) {
            for (j in buttons[i].indices) {
                buttons[i][j].text = ""
            }
        }
        roundCount = 0
        playerXTurn = true
    }

    private fun resetGame() {
        resetBoard()
        roundCount = 0
        playerXTurn = true
    }

    private fun showToast(message: String) {
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show()
    }
}
