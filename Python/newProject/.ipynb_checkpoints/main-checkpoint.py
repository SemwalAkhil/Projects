import pandas as pd

df = pd.read_csv(r'D:\Projects\Python\newProject\data.csv')
print(df.shape)
df.drop_duplicates(["Scorecard"])
df.reset_index()
print(df.shape)
