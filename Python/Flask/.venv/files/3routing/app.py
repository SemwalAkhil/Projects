from flask import Flask
app = Flask(__name__)

@app.route("/")
def index():
    return "Home Page"

@app.route("/1")
def hello():
    return "page1"