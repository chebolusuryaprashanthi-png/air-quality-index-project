import pandas as pd
import matplotlib.pyplot as plt
from statsmodels.tsa.arima.model import ARIMA

# Sample AQI data (replace with your dataset if available)
data = [80, 85, 90, 120, 150, 200, 180, 160, 140, 130, 110, 100]

# Convert to DataFrame
df = pd.DataFrame(data, columns=['AQI'])

# Plot original data
plt.plot(df['AQI'])
plt.title("AQI Trend")
plt.xlabel("Days")
plt.ylabel("AQI")
plt.show()

# ARIMA Model
model = ARIMA(df['AQI'], order=(2,1,2))
model_fit = model.fit()

# Forecast next 5 days
forecast = model_fit.forecast(steps=5)

print("Future AQI Prediction:")
print(forecast)

# Plot forecast
plt.plot(df['AQI'], label="Original")
plt.plot(range(len(df), len(df)+5), forecast, label="Forecast")
plt.legend()
plt.show()
