package com.example.practicecomposequadrant

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.material3.Card
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.LineHeightStyle
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.example.practicecomposequadrant.ui.theme.PracticeComposeQuadrantTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            PracticeComposeQuadrantTheme {
                Scaffold(modifier = Modifier.fillMaxSize()) { innerPadding ->
                    DisplayFunc(modifier = Modifier.padding(innerPadding))
                }
            }
        }
    }
}

@Composable
@Preview (showBackground = true)
fun DisplayFuncPreview(){
    DisplayFunc()
}
@Composable
fun DisplayFunc(modifier: Modifier = Modifier) {
    Column(modifier = modifier) {
        Row(modifier = Modifier.weight(1f,fill = true), verticalAlignment = Alignment.CenterVertically) {
            CardFunc(heading = stringResource(R.string.heading1), body = stringResource(R.string.body1), modifier = Modifier
                .background(Color(0xFFEADDFF))
                .weight(1f, fill = true))
            CardFunc(heading = stringResource(R.string.heading2), body = stringResource(R.string.body2), modifier = Modifier
                .background(Color(0xFFD0BCFF))
                .weight(1f, fill = true))
        }
        Row(modifier = Modifier.weight(1f,fill = true), verticalAlignment = Alignment.CenterVertically) {
            CardFunc(heading = stringResource(R.string.heading3), body = stringResource(R.string.body3), modifier = Modifier
                .background(Color(0xFFB69DF8))
                .weight(1f, fill = true))
            CardFunc(heading = stringResource(R.string.heading4), body = stringResource(R.string.body4), modifier = Modifier
                .background(Color(0xFFF6EDFF))
                .weight(1f, fill = true))
        }
    }
}
@Composable
fun CardFunc(modifier: Modifier = Modifier, heading: String, body: String) {
    Box(modifier = modifier
        .fillMaxSize()
        .padding(16.dp) , contentAlignment = Alignment.Center){
        Column(modifier = Modifier, verticalArrangement = Arrangement.Center, horizontalAlignment = Alignment.CenterHorizontally) {
            Text(text = heading, modifier = Modifier.padding(bottom = 16.dp), fontWeight = FontWeight.Bold)
            Text(text = body, modifier = Modifier, textAlign = TextAlign.Justify)
        }
    }
}