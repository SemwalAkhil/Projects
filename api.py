import google.generativeai as genai
import markdown
import requests

API_KEY = "AIzaSyCOQiz6vJzfVQzQWzcisQv_BQbcaQQVC68"

def createModel(API_KEY:str):
  genai.configure(api_key=API_KEY)
  model = genai.GenerativeModel("gemini-1.5-flash")
  return model

def getTextResponse(text:str,model:genai.GenerativeModel):
  response = model.generate_content(text)
  return response.text

def getLocalImageResponse(model:genai.GenerativeModel,filePath:str,fileName:str):
  sample_file = genai.upload_file(path=filePath,display_name=fileName)
  file = genai.get_file(name=sample_file.name)
  print(f"Retrieved file '{file.display_name}' as: {sample_file.uri}")

  # Prompt the model with text and the previously uploaded image.
  response = model.generate_content([sample_file, "Describe this."])

  print(response.text)

def getOnlineImageResponse(model:genai.GenerativeModel,filePath:str,fileName:str):
  sample_file = genai.upload_file(path=filePath,display_name=fileName)
  file = genai.get_file(name=sample_file.name)
  print(f"Retrieved file '{file.display_name}' as: {sample_file.uri}")

  # Prompt the model with text and the previously uploaded image.
  response = model.generate_content([sample_file, "Describe this."])

  print(response.text)

def downloadImage(url:str):
  # Send a GET request to download the file
  response = requests.get(url)

  # Check for successful download (status code 200)
  if response.status_code == 200:
    # Get the filename (optional, can be extracted from URL)
    filename = url.split("/")[-1]

    # Open the file in binary write mode
    with open(filename, "wb") as file:
      file.write(response.content)
    print(f"Downloaded file: {filename}")
  else:
    print(f"Download failed: {response.status_code}")

# url = r"D:\Projects\PythonRegX.png"
# fileName = "Random"
# model = createModel(API_KEY)
# getLocalImageResponse(model=model,filePath=url,fileName=fileName)

