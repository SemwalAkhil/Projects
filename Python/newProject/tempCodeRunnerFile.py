# Create a table object
plt.table(cellText=ipl.values, colLabels=ipl.columns, loc='center')

# Turn off axis to focus on the table
plt.axis('off')

# Display the figure
plt.show()
