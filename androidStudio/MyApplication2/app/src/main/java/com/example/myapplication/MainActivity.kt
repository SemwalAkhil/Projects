package com.example.notesfy

import android.os.Build
import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.annotation.RequiresApi
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import okhttp3.Call
import okhttp3.Callback
import okhttp3.MediaType.Companion.toMediaTypeOrNull
import okhttp3.OkHttpClient
import okhttp3.Request
import okhttp3.RequestBody.Companion.toRequestBody
import okhttp3.Response
import okio.IOException
import org.json.JSONArray
import org.json.JSONObject

class FarmerGpt : AppCompatActivity() {
    private val client = OkHttpClient()

    @RequiresApi(Build.VERSION_CODES.P)
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_farmer_gpt)

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val btnFarmerGpt = findViewById<Button>(R.id.btn_farmergpt)
        val farmerGptEdit = findViewById<EditText>(R.id.farmerGptedit)
        val gptContent = findViewById<TextView>(R.id.gptcontant)

        btnFarmerGpt.setOnClickListener {
            val question = farmerGptEdit.text.toString()
            if (question.isNotBlank()) {
                getQuestion(question) { response ->
                    runOnUiThread {
                        gptContent.text = response
                    }
                }
            } else {
                Toast.makeText(this, "Please enter a question", Toast.LENGTH_SHORT).show()
            }
        }
    }

    @RequiresApi(Build.VERSION_CODES.P)
    fun getQuestion(question: String, callback: (String) -> Unit) {
        val apiKey = "YOUR_API_KEY" // Move this to a secure location
        val url = "https://api.openai.com/v1/completions"
        val requestBody = """
            {
                "prompt": "$question",
                "max_tokens": 500,
                "model": "text-davinci-003",
                "temperature": 0
            }
        """.trimIndent()

        val request = Request.Builder()
            .url(url)
            .addHeader("Content-Type", "application/json")
            .addHeader("Authorization", "Bearer $apiKey")
            .post(requestBody.toRequestBody("application/json".toMediaTypeOrNull()))
            .build()

        client.newCall(request).enqueue(object : Callback {
            override fun onFailure(call: Call, e: IOException) {
                Log.e("error", "Request failed: ${e.message}")
            }

            override fun onResponse(call: Call, response: Response) {
                if (!response.isSuccessful) {
                    Log.e("error", "Unexpected response code: ${response.code}")
                    return
                }

                response.body?.string()?.let { body ->
                    Log.v("data", body)
                    val jsonObject = JSONObject(body)
                    val jsonArray: JSONArray = jsonObject.getJSONArray("choices")
                    val result: String = jsonArray.getJSONObject(0).getString("text").trim()

                    // Log the result before calling the callback
                    Log.v("result", result)
                    callback(result)
                } ?: Log.v("data", "Empty response body")
            }
        })
    }
}