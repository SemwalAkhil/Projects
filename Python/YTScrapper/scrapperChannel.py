from googleapiclient.discovery import build
from dotenv import load_dotenv
import os

load_dotenv(r"D:\Projects\Python\YTScrapper\.env.local")

# Replace with your API key
API_KEY = os.getenv("API_KEY")

# Build the YouTube service
youtube = build('youtube', 'v3', developerKey=API_KEY)

def get_channel_id_by_custom_url(custom_url):
    # Search for the channel by custom URL
    search_request = youtube.search().list(
        part='snippet',
        q=custom_url,
        type='channel'
    )
    search_response = search_request.execute()

    channel_id = search_response['items'][0]['snippet']['channelId']
    return channel_id

CHANNEL_ID = get_channel_id_by_custom_url("https://www.youtube.com/sureshbadamath")

# Function to get the uploads playlist ID from the channel
def get_uploads_playlist_id(channel_id):
    # Fetch channel details to get the uploads playlist ID
    channel_request = youtube.channels().list(
        part='contentDetails',
        id=channel_id
    )
    channel_response = channel_request.execute()
    
    uploads_playlist_id = channel_response['items'][0]['contentDetails']['relatedPlaylists']['uploads']
    return uploads_playlist_id

# Function to get video descriptions from the uploads playlist
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

# Get uploads playlist ID
uploads_playlist_id = get_uploads_playlist_id(CHANNEL_ID)

# Fetch descriptions
descriptions = get_video_descriptions(uploads_playlist_id)

# Save descriptions to a text file
with open(r'D:\Projects\Python\YTScrapper\channel_video_descriptions.txt', 'w', encoding='utf-8') as f:
    for i, desc in enumerate(descriptions, 1):
        f.write(f"Description of video {i}:\n{desc}\n\n")

print("Descriptions saved to channel_video_descriptions.txt")


