import pandas as pd

currency_rating = pd.read_csv("currency_rating_2019.csv",engine = "python", delimiter = ";", encoding="cp1250", decimal = ",", sep = ",")

print(currency_rating)
print(currency_rating.columns)
print("\n")
print(currency_rating[['data','1USD']])
print("\n")
print("\n")
#print("{0} {1}",currency_rating[['data']][0:-2],currency_rating[['1USD']][0:-2].min())
#print(currency_rating[['1USD']][0:-2].min())
min_usd = currency_rating[['1USD']][2:-3].astype('float64')
row_id = min_usd.idxmin();
print(currency_rating.loc[row_id])