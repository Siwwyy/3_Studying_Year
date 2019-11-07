import pandas as pd
import matplotlib
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import pylab


def select_columns(data_frame, column_names):
    new_frame = data_frame.loc[:, column_names]
    return new_frame


currency_rating = pd.read_csv("currency_rating_2019.csv",engine = "python", delimiter = ";", encoding="cp1250", decimal = ",", sep = ",")

#print(currency_rating)
#print(currency_rating.columns)
#print("\n")
#print(currency_rating[['data','1USD']])
#print("\n")
#print("\n")
#print("{0} {1}",currency_rating[['data']][0:-2],currency_rating[['1USD']][0:-2].min())
#print(currency_rating[['data']][0:-2])
#print(currency_rating[['1USD']][0:-2].min())
#min_usd = currency_rating[['1USD']][2:-3].astype('float64')
#print(currency_rating.loc[row_id])

#average = currency_rating[['1USD']][0:-2].mean();
#print("Average: ", average);#currency_rating[['data']]>'20190101' & currency_rating[['data']]<'20191010']
#data_frame = pd.DataFrame(currency_rating)
#selected_columns = ['data','1USD']
#data_frame_copy = select_columns(data_frame, selected_columns)
##print(data_frame)
#print(data_frame_copy)
#mask = (data_frame_copy['data'] > '20190101') & (data_frame_copy['data'] < '20191010')
#average = (data_frame_copy.loc[mask, '1USD']).astype('float64')
#mediana = (data_frame_copy.loc[mask, '1USD']).astype('float64')
#print("Average: ", average.mean())
#print("Median: ", mediana.median())
#print("Average: ", ((currency_rating[['1USD']][1:-3]).astype('float64')).mean())
#print("Average: ", ((currency_rating[['1USD']][1:-3]).astype('float64')).median())
data_frame = pd.DataFrame(currency_rating)
selected_columns = ['data','1USD']
data_frame_copy = select_columns(data_frame, selected_columns)


def Average_Median_Specified_Month(currency,from_date,to_date,data_frame_1):
#    print(data_frame_copy)
    mask = (data_frame_1['data'] > from_date) & (data_frame_1['data'] < to_date)
    average = (data_frame_1.loc[mask, currency]).astype('float64')
    mediana = (data_frame_1.loc[mask, currency]).astype('float64')
    print("++++++++++++++++++++++++++++++++++++")
    print("     Date: {0} to {1}".format(from_date, to_date))
    print("     Average: ", average.mean())
    print("     Median: ", mediana.median())
    print("++++++++++++++++++++++++++++++++++++")


def Plot_Something(currency,from_date,to_date,data_frame_1):
    mask = (data_frame_1['data'] > from_date) & (data_frame_1['data'] < to_date)
    #plt.figure(figsize = (200,200))
    fig= plt.figure(figsize=(10,10))

    axes= fig.add_axes([0.1,0.1,0.8,0.8])

    x = (data_frame_1.loc[mask, currency]).astype('float64')
    #y = pd.to_numeric(data_frame_1['data'][mask],errors='coerce')
    #array = pd.to_numeric(data_frame_1['data'][mask]).astype(int)
    y = pd.to_numeric(data_frame_1['data'][mask]).astype(int)
    #print(array[mask])
    axes.plot(x,y)
    plt.show()
    #print(pd.to_numeric(data_frame_1['data'][mask]).astype('float64'))



######################################################################################
######################################################################################
######################################################################################

#Average_Median_Specified_Month('1USD','20190101','20190831',data_frame_copy) 
#Plot_Something('1USD','20190101','20190831',data_frame_copy)

#img=mpimg.imread('download.png')
#imgplot = plt.imshow(img)

#from cv2
#image = Image.open("download.png")
#image.show()