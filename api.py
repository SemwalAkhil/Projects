from openai import OpenAI
API_KEY = "sk-proj-wiX3awPjdflwdccOncXMT3BlbkFJWBrJ2k7RWqTvZfk18zSG"
client = OpenAI(api_key=API_KEY)

completion = client.chat.completions.create(
  model="gpt-3.5-turbo",
  messages=[
    {"role": "system", "content": "You are a poetic assistant, skilled in explaining complex programming concepts with creative flair."}
  ]
)

print(completion.choices[0].message)
