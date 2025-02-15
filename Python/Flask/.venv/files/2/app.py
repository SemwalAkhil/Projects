from flask import Flask
from markupsafe import escape

app = Flask(__name__)

@app.route("/")
def home(name="<script>alert('bad')</script>"):
    """
    When returning HTML (the default response type in Flask), any user-provided values rendered in the output must be escaped to protect from injection attacks. HTML templates rendered with Jinja, introduced later, will do this automatically.
    
    return f"Hello, {name}!"
    
    """
    return f"Hello, {escape(name)}!"
    """
    escape(), shown here, can be used manually.
    If a user managed to submit the name <script>alert("bad")</script>, escaping causes it to be rendered as text, rather than running the script in the user's browser.
    """