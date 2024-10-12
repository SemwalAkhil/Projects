from googleapiclient.discovery import build
from dotenv import load_dotenv
import os

load_dotenv(r"D:\Projects\Python\YTScrapper\.env.local")

# Replace with your API key
API_KEY = os.getenv("API_KEY")
PLAYLIST_ID = 'PLldEapv0nG30gNYWzAe27ThsIkWbVwL95'

# Build the YouTube service
youtube = build('youtube', 'v3', developerKey=API_KEY)

# Function to get video details from the playlist
def get_video_descriptions(playlist_id):
    video_descriptions = []
    next_page_token = None

    while True:
        # Fetch playlist items (videos)
        playlist_request = youtube.playlistItems().list(
            part='contentDetails',
            playlistId=playlist_id,
            maxResults=50,
            pageToken=next_page_token
        )
        playlist_response = playlist_request.execute()

        video_ids = [item['contentDetails']['videoId'] for item in playlist_response['items']]

        # Fetch video details including description
        video_request = youtube.videos().list(
            part='snippet',
            id=','.join(video_ids)
        )
        video_response = video_request.execute()

        for video in video_response['items']:
            description = video['snippet']['description']
            video_descriptions.append(description)

        next_page_token = playlist_response.get('nextPageToken')
        if not next_page_token:
            break

    return video_descriptions

# Fetch descriptions
descriptions = get_video_descriptions(PLAYLIST_ID)
# Save descriptions to a text file
with open(r'D:\Projects\Python\YTScrapper\video_descriptions.txt', 'w', encoding='utf-8') as f:
    for i, desc in enumerate(descriptions, 1):
        f.write(f"Description of video {i}:\n{desc}\n\n")

print("Descriptions saved to video_descriptions.txt")

    