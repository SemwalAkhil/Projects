# # import os
# # from openai import OpenAI

# # client = OpenAI(api_key=os.environ["sk-proj-yecPqgfEpajqTrNyEd0AT3BlbkFJo6W8mx7oNyUo2c3Y7a71"])

# # #  # this is also the default, it can be omitted

# # def chat_with_gpt(prompt):
# #     response = client.chat.completions.create(
# #         model = "gpt-4o",
# #         messages=[{"role":"user","content":prompt}]
# #     )

# #     return response.choices[0].message.content

# # if __name__ == "__main__":
# #     while True:
# #         user_input = input("You: ")
# #         if user_input.lower() in ["quit","exit","bye"]:
# #             break
# #         response = chat_with_gpt(user_input)
# #         print("Chatbot: ",response)

# import os
# import openai
# import requests

# # Set your OpenAI API key
# api_key = os.getenv("sk-proj-hI7ke00myVsoCnA64tznT3BlbkFJtR9s1L7J2xR9viuQE0K9")
# openai.api_key = api_key

# def stream_chat_with_gpt(prompt):
#     response = requests.post(
#         "https://api.openai.com/v1/chat/completions",
#         headers={
#             "Authorization": f"Bearer {api_key}",
#             "Content-Type": "application/json"
#         },
#         json={
#             "model": "gpt-3.5-turbo-0125",  # Ensure you use the correct model identifier
#             "messages": [{"role": "user", "content": prompt}],
#             "stream": True
#         },
#         stream=True
#     )

#     for line in response.iter_lines():
#         print("p1")
#         if line:
#             print("p2")
#             decoded_line = line.decode('utf-8')
#             print(decoded_line)
#             if decoded_line.startswith("data: "):
#                 print("p3")
#                 data = decoded_line[6:]
#                 if data == "[DONE]":
#                     print("p4")
#                     break
#                 print("Chatbot:", data)

# if __name__ == "__main__":
#     while True:
#         user_input = input("You: ")
#         if user_input.lower() in ["quit", "exit", "bye"]:
#             break
#         stream_chat_with_gpt(user_input)

import openai
from openai import OpenAI

openai.api_key ="sk-proj-hI7ke00myVsoCnA64tznT3BlbkFJtR9s1L7J2xR9viuQE0K9"

def chat_with_gpt(prompt):
    response = openai.ChatCompletion.create(model="gpt-3.5-turbo",messages=[{"role": "user", "content": prompt}])
    return response.choices[0].message.content.strip()

if __name__ == "_main__":
    print("Started")
    while True:
        user_input = input("You: ")
        if user_input.lower() in ["quit", "exit", "bye"]:
            break
        response = chat_with_gpt(user_input)
        print("Chatbot: ", response)

