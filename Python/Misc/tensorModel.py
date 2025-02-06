import pandas as pd
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder, StandardScaler

# Load the data
file_path = 'updated_pklData.csv'  # Path to your data file
df = pd.read_csv(file_path)

# Print columns to ensure correct names
print(df.columns)

# Filter data to only include matches between Haryana Steelers and UP Yoddhas
df_filtered = df[(df['Team_A'] == 'Haryana Steelers') | (df['Team_B'] == 'Haryana Steelers')]

# Define the function to determine the winner and calculate margin
def determine_winner_and_margin(row):
    margin = abs(row['Points_A'] - row['Points_B'])
    if row['Points_A'] > row['Points_B']:
        return row['Team_A'], margin
    elif row['Points_B'] > row['Points_A']:
        return row['Team_B'], margin
    else:
        return 'Draw', margin  # In case of a tie

# Apply the function to the DataFrame to create the 'Winner' and 'Margin' columns
df_filtered[['Winner', 'Margin']] = df_filtered.apply(
    lambda row: pd.Series(determine_winner_and_margin(row)), axis=1
)

# Encode categorical data using LabelEncoder
label_encoder = LabelEncoder()

# Encoding the 'Team A' and 'Team B' columns
df_filtered['Team_A'] = label_encoder.fit_transform(df_filtered['Team_A'])
df_filtered['Team_B'] = label_encoder.fit_transform(df_filtered['Team_B'])

# Encoding the 'Winner' column
df_filtered['Winner'] = label_encoder.fit_transform(df_filtered['Winner'])

# Features and target
X = df_filtered[['Team_A', 'Team_B', 'Points_A', 'Points_B', 'Margin']]  # Features
y = df_filtered['Winner']  # Target (Winner)

# Scaling the features
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.2, random_state=42)

# Building the neural network model
model = Sequential()
model.add(Dense(64, input_dim=X_train.shape[1], activation='relu'))
model.add(Dense(32, activation='relu'))
model.add(Dense(1, activation='sigmoid'))  # Sigmoid activation for binary classification (win/loss)

# Compile the model
model.compile(loss='binary_crossentropy', optimizer='adam', metrics=['accuracy'])

# Train the model
model.fit(X_train, y_train, epochs=50, batch_size=32, validation_data=(X_test, y_test))

# Evaluate the model
loss, accuracy = model.evaluate(X_test, y_test)
print(f"Test Accuracy: {accuracy * 100:.2f}%")

# Predict the winners for the test set
predictions = model.predict(X_test)
predictions = (predictions > 0.5).astype(int)

# Convert predictions back to team names
predicted_winners = label_encoder.inverse_transform(predictions.flatten())

# Print some predictions to check the results
print(predicted_winners[:10])

# Optionally, you can save the updated DataFrame with predictions
df_filtered.to_csv('updated_pklData_with_predictions_haryana_up.csv', index=False)
