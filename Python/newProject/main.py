import pandas as pd
import numpy as numpy
import matplotlib.pyplot as plt

import seaborn as sns
# Seaborn is a Python data visualization library based on matplotlib. It provides a high-level interface for drawing attractive and informative statistical graphics.

import warnings
# Warning messages are typically issued in situations where it is useful to alert the user of some condition in a program, where that condition (normally) doesn’t warrant raising an exception and terminating the program. For example, one might want to issue a warning when a program uses an obsolete module.

warnings.filterwarnings("ignore")
# The warnings filter controls whether warnings are ignored, displayed, or turned into errors (raising an exception).
# Conceptually, the warnings filter maintains an ordered list of filter specifications; any specific warning is matched against each filter specification in the list in turn until a match is found; the filter determines the disposition of the match.

ipl = pd.read_csv("data.csv",encoding_errors="ignore")
pd.set_option("display.max_columns",100)
ipl.head()
# print(ipl)
# print(ipl.shape)
# print(ipl.values)
# print(ipl.columns)
# print(ipl.describe())

# # Create a table object
# plt.table(cellText=ipl.values, colLabels=ipl.columns, loc='center')

# # Turn off axis to focus on the table
# plt.axis('off')

# # Display the figure
# plt.show()
