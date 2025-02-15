"""
First we imported the Flask class. An instance of this class will be our WSGI application.
"""
from flask import Flask

"""
Next we create an instance of this class. The first argument is the name of the application's module or package. __name__ is a convenient shortcut for this that is appropriate for most cases. This is needed so that Flask knows where to look for resources such as templates and static files.
"""
app = Flask(__name__)

"""
We then use the route() decorator to tell Flask what URL should trigger our function.
The function returns the message we want to display in the user's browser. The default content type is HTML, so HTML in the string will be rendered by the browser.
"""
@app.route("/")
def hello_world():
    return "<p>Hello World</<p>"

# flask --app D:\Projects\Python\Flask\.venv\files\1\1.py run
#  if the file is named app.py or wsgi.py, you don’t have to use --app

"""
If you run the server you will notice that the server is only accessible from your own computer, not from any other in the network. This is the default because in debugging mode a user of the application can execute arbitrary Python code on your computer.

If you have the debugger disabled or trust the users on your network, you can make the server publicly available simply by adding --host=0.0.0.0 to the command line:

flask --app D:\Projects\Python\Flask\.venv\files\1\1.py run --host=0.0.0.0
"""
# Debug Mode
"""
The flask run command can do more than just start the development server. By enabling debug mode, the server will automatically reload if code changes, and will show an interactive debugger in the browser if an error occurs during a request.
The debugger allows executing arbitrary Python code from the browser. It is protected by a pin, but still represents a major security risk. Do not run the development server or debugger in a production environment.
"""