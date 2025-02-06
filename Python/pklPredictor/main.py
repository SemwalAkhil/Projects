# # %%
# import pandas as pd
# import json
# from sklearn.model_selection import train_test_split
# from sklearn.ensemble import RandomForestClassifier
# from sklearn.metrics import accuracy_score
# from sklearn.feature_extraction.text import CountVectorizer
# from sklearn.pipeline import make_pipeline
# import random

# # Load the JSON data
# with open(r'D:\Projects\pklData.json', 'r') as file:
#     data = json.load(file)

# # Extract features and labels from the data
# seasons = data[0]

# def getMatch(seasons:dict,season:str,match:str)->dict:
#     try:
#         team1, team1_score, team1_players, team2, team2_score, team2_players = seasons[season][match]
#         team1_player_names = ' '.join([list(player.keys())[0] for player in team1_players])
#         team2_player_names = ' '.join([list(player.keys())[0] for player in team2_players])
#         # Create a match record
#         return {
#             'team1': team1,
#             'team1_players': team1_player_names,
#             'team1_score': int(team1_score),
#             'team2': team2,
#             'team2_players': team2_player_names,
#             'team2_score': int(team2_score),
#             'outcome': 1 if team1_score > team2_score else 0  # 1 if team1 wins, else 0
#         }
#     except:
#         return {}
    

# def getMatches(seasons:dict,season:str)->list:
#     matches = []
#     matchNums = seasons[season].keys()
#     for match in matchNums:
#         temp = getMatch(seasons,season,match)
#         if (temp):
#             matches.append(temp)
#     return matches

# def getSeasons(seasons:dict)->list:
#     seasonNums = seasons.keys()
#     matches = []
#     for season in seasonNums:
#         matches += getMatches(seasons,season)
#     return matches
    
    
# getSeasons(seasons)
# # %%
# # Convert to DataFrame
# df = pd.DataFrame(getSeasons(seasons))

# # Define features and labels
# X = df[['team1', 'team1_players', 'team2', 'team2_players']]
# y = df['outcome']
# # %%
# # Create a pipeline with text vectorization and Random Forest Classifier
# pipeline = make_pipeline(
#     CountVectorizer(analyzer=lambda x: x.split()),
#     RandomForestClassifier(random_state=42)
# )

# # Combine team and player data for text vectorization
# X_combined = X['team1'] + ' ' + X['team1_players'] + ' ' + X['team2'] + ' ' + X['team2_players']

# # Split the data
# X_train, X_test, y_train, y_test = train_test_split(X_combined, y, test_size=0.2, random_state=42)

# # Train the pipeline
# pipeline.fit(X_train, y_train)

# # Evaluate the model
# y_pred = pipeline.predict(X_test)
# print("Accuracy:", accuracy_score(y_test, y_pred))

# # %%
# with open(r'D:\Projects\pklData.json', 'r') as file:
#     data = json.load(file)
# seasons = data[0]
# while True:
#     try:
#         test = list(getMatch(seasons,f"{random.randint(1,11)}",f"{random.randint(1,100)}").values())
#         break
#     except:
#         pass
# testStr = ""
# for i in test:
#     if (not str(i).isnumeric()):
#         testStr += " "+i
# # # print(testStr)
# # %%
# # Predict outcomes for new data
# print(test,"\n",testStr)
# new_match = pd.Series([testStr])
# print("Predicted outcome:", pipeline.predict(new_match))

# %%
import pandas as pd
import json
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import Pipeline
import random

# Load the JSON data
with open(r'D:\Projects\pklData.json', 'r') as file:
    data = json.load(file)

# Extract features and labels from the data
seasons = data[0]

def getMatch(seasons:dict,season:str,match:str)->dict:
    try:
        team1, team1_score, team1_players, team2, team2_score, team2_players = seasons[season][match]
        
        # Aggregate stats for team 1
        team1_stats = {'Total Pts': 0, 'Touch Pts': 0, 'Bonus Pts': 0, 'Tackle Pts': 0}
        for player in team1_players:
            player_name = list(player.keys())[0]
            stats = player[player_name]
            for key in team1_stats:
                team1_stats[key] += int(stats[key])

        # Aggregate stats for team 2
        team2_stats = {'Total Pts': 0, 'Touch Pts': 0, 'Bonus Pts': 0, 'Tackle Pts': 0}
        for player in team2_players:
            player_name = list(player.keys())[0]
            stats = player[player_name]
            for key in team2_stats:
                team2_stats[key] += int(stats[key])

        team1_player_names = ' '.join([list(player.keys())[0] for player in team1_players])
        team2_player_names = ' '.join([list(player.keys())[0] for player in team2_players])
        
        # Create a match record
        return {
            'team1': team1,
            'team1_players': team1_player_names,
            'team1_stats': team1_stats,
            'team1_score': int(team1_score),
            'team2': team2,
            'team2_players': team2_player_names,
            'team2_stats': team2_stats,
            'team2_score': int(team2_score),
            'outcome': 1 if team1_score > team2_score else 0  # 1 if team1 wins, else 0
        }
    except:
        return {}
    

def getMatches(seasons:dict,season:str)->list:
    matches = []
    matchNums = seasons[season].keys()
    for match in matchNums:
        temp = getMatch(seasons,season,match)
        if (temp):
            matches.append(temp)
    return matches

def getSeasons(seasons:dict)->list:
    seasonNums = seasons.keys()
    matches = []
    for season in seasonNums:
        matches += getMatches(seasons,season)
    return matches
    
    
getSeasons(seasons)
# %%
# Convert to DataFrame
df = pd.DataFrame(getSeasons(seasons))

# Add team stats as features
df['team1_total_pts'] = df['team1_stats'].apply(lambda x: x['Total Pts'])
df['team1_touch_pts'] = df['team1_stats'].apply(lambda x: x['Touch Pts'])
df['team2_total_pts'] = df['team2_stats'].apply(lambda x: x['Total Pts'])
df['team2_touch_pts'] = df['team2_stats'].apply(lambda x: x['Touch Pts'])

# Define features and labels
df['combined_text'] = df['team1'] + ' ' + df['team1_players'] + ' ' + df['team2'] + ' ' + df['team2_players']
X = df[['combined_text', 'team1_total_pts', 'team1_touch_pts', 'team2_total_pts', 'team2_touch_pts']]
y = df['outcome']

# Define text and numeric transformers
text_transformer = CountVectorizer(analyzer=lambda x: x.split())
numeric_transformer = StandardScaler()

# Combine transformers for text and numeric features
preprocessor = ColumnTransformer(
    transformers=[
        ('text', text_transformer, 'combined_text'),
        ('num', numeric_transformer, ['team1_total_pts', 'team1_touch_pts', 'team2_total_pts', 'team2_touch_pts'])
    ]
)

# Create the final pipeline
pipeline = Pipeline(steps=[
    ('preprocessor', preprocessor),
    ('classifier', RandomForestClassifier(random_state=42))
])

# Split the data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Train the pipeline
pipeline.fit(X_train, y_train)

# Evaluate the model
y_pred = pipeline.predict(X_test)
print("Accuracy:", accuracy_score(y_test, y_pred))

# %%
def get_avg_stats(players, historical_data):
    avg_stats = {'Total Pts': 0, 'Touch Pts': 0, 'Bonus Pts': 0, 'Tackle Pts': 0}
    for player in players.split():
        player_stats = historical_data.get(player, avg_stats)
        for key in avg_stats:
            avg_stats[key] += player_stats[key]
    return {key: val / len(players.split()) for key, val in avg_stats.items()}

# Example for new match
team1_players = "PlayerA PlayerB PlayerC"
team2_players = "PlayerX PlayerY PlayerZ"

# Historical data should be precomputed based on averages from training data
historical_data = {
    "PlayerA": {'Total Pts': 5, 'Touch Pts': 3, 'Bonus Pts': 1, 'Tackle Pts': 1},
    "PlayerB": {'Total Pts': 6, 'Touch Pts': 4, 'Bonus Pts': 1, 'Tackle Pts': 1},
    "PlayerC": {'Total Pts': 7, 'Touch Pts': 5, 'Bonus Pts': 1, 'Tackle Pts': 1},
    "PlayerX": {'Total Pts': 8, 'Touch Pts': 6, 'Bonus Pts': 1, 'Tackle Pts': 1},
    "PlayerY": {'Total Pts': 5, 'Touch Pts': 2, 'Bonus Pts': 1, 'Tackle Pts': 2},
    "PlayerZ": {'Total Pts': 6, 'Touch Pts': 4, 'Bonus Pts': 1, 'Tackle Pts': 1}
}

team1_stats = get_avg_stats(team1_players, historical_data)
team2_stats = get_avg_stats(team2_players, historical_data)

new_match = pd.DataFrame([{
    'combined_text': f"Team1 {team1_players} Team2 {team2_players}",
    'team1_total_pts': team1_stats['Total Pts'],
    'team1_touch_pts': team1_stats['Touch Pts'],
    'team2_total_pts': team2_stats['Total Pts'],
    'team2_touch_pts': team2_stats['Touch Pts']
}])

# Predict the outcome
print("Predicted outcome:", pipeline.predict(new_match))
