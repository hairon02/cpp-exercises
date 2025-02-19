import yfinance as yf
import pandas as pd

# Definir el ticker de Intel
ticker = 'INTC'

# Definir el rango de tiempo (últimos 10 años)
data = yf.download(ticker, start='2013-01-01', end='2023-12-31')

# Guardar los datos en un archivo CSV
data.to_csv('intel_10_años.csv')

print("Datos descargados y guardados en 'intel_10_años.csv'")
