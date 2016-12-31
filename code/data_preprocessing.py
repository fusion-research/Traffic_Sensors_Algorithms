from TrafficDataClass import *
import time
from datetime import timedelta
import glob

"""
This script is used to visualize the datasets collected in the field: 1013, 1027, 1103, 1116, 1118
"""
__author__ = 'Yanning Li'


# ================================================================================
# configuration
# ================================================================================

# --------------------------------------------------
# dataset 1003:
# - Neil street. Freeflow and stop-and-to in total 33 min
# - One PIR sensor array 4x32, at 64 Hz
# --------------------------------------------------
folder = '../datasets/1013_2016/'
# dataset = '1310-205905'   # initial 10 second
# dataset = '1310-213154'   # freeflow part 1
# dataset='1310-210300'     # freeflow part 2
dataset='1310-221543'       # stop and go

fps = 64

data_key = 'raw_data'

# ================================================================================
temp_data_file = folder + '{0}.txt'.format(dataset)

data = TrafficData()
# dt = timedelta(seconds=3)

periods = data.get_txt_data_periods(folder+'*.txt', update=True)

data.load_txt_data(file_name_str=temp_data_file, dataset=dataset, data_key=data_key)


# ================================================================================
# Check sampling frequency
# ================================================================================
# data.plot_sample_timing(dataset=dataset)


# ================================================================================
# Plot the evolution of noise for a pixel
# ================================================================================

# data.plot_noise_evolution(dataset=dataset, data_key=data_key, p_outlier=0.01, stop_thres=(0.1,0.01),
#                       pixel=(0,0), window_s=10, step_s=1.0/16.0, fps=fps)
#
# data.plot_noise_evolution(dataset=dataset, data_key=data_key, p_outlier=0.01, stop_thres=(0.1,0.01),
#                       pixel=(0,15), window_s=10, step_s=1.0/16.0, fps=fps)

# data.plot_noise_evolution(dataset=dataset, data_key=data_key, p_outlier=0.01, stop_thres=(0.1,0.01),
#                       pixel=(1,5), window_s=5, step_s=1.0/16.0, fps=fps)
#
# data.plot_noise_evolution(dataset=dataset, data_key=data_key, p_outlier=0.01, stop_thres=(0.1,0.01),
#                       pixel=(1,20), window_s=5.0, step_s=1.0, fps=fps)
#
# data.plot_noise_evolution(data_key=data_key, p_outlier=0.01, stop_thres=(0.1,0.01),
#                       pixel=(2,10), window_s=5, step_s=1.0, fps=fps)

# data.plot_noise_evolution(dataset=dataset, data_key=data_key, p_outlier=0.01, stop_thres=(0.1,0.01),
#                       pixel=(3,0), window_s=10, step_s=1.0/16.0, fps=fps)
#
# data.plot_noise_evolution(dataset=dataset, data_key=data_key, p_outlier=0.01, stop_thres=(0.1,0.01),
#                       pixel=(3,15), window_s=10, step_s=1.0/16.0, fps=fps)



# ================================================================================
# Check the noise mean and standard deviation
# They are saved in ../figs/
# ================================================================================
# mu, sigma, noise_mu, noise_sigma = data.get_noise_distribution(dataset=dataset, data_key='temp_data',
#                             t_start=periods[dataset][0]+timedelta(seconds=3),
#                             t_end=periods[dataset][1],
#                             p_outlier=0.01, stop_thres=(0.1, 0.01),pixels=None, suppress_output=True)
# # Overall mean and std
# data.cus_imshow(data_to_plot=mu, cbar_limit=None, title='mean for {0}'.format(dataset),
#                 annotate=True, save_name='{0}_mu'.format(dataset))
# data.cus_imshow(data_to_plot=sigma, cbar_limit=None, title='std for {0}'.format(dataset),
#                 annotate=True, save_name='{0}_std'.format(dataset))
#
# noise mean and std
# data.cus_imshow(data_to_plot=noise_mu,cbar_limit=None,title='noise mean for {0}'.format(dataset),
#                 annotate=True, save_name='{0}_noise_mu'.format(dataset))
# data.cus_imshow(data_to_plot=noise_sigma,cbar_limit=None,title='noise std for {0}'.format(dataset),
#                 annotate=True, save_name='{0}_noise_std'.format(dataset))



# ================================================================================
# Plot the histogram of a pixel during a peirod.
# ================================================================================
# data.plot_histogram_for_pixel(dataset=dataset, data_key='temp_data',pixels=[(1,8)],
#                               t_start=periods[dataset][0]+timedelta(seconds=33),
#                               t_end=periods[dataset][0]+timedelta(seconds=633))


# ================================================================================
# Normalize the data and visualize in heat maps
# ================================================================================
data.normalize_data(data_key=data_key, norm_data_key=None,
                    t_start=None, t_end=None, p_outlier=0.01, stop_thres=(0.1, 0.01),
                    window_s=5, step_s=1, fps=64)

data.plot_heat_map_in_period(data_key='norm_'+data_key,
                             t_start= periods[dataset][0],
                             t_end=periods[dataset][1],
                             cbar_limit=(2,6), option='vec', nan_thres_p=0.98,
                             plot=True, folder=None, save_img=False, save_npy=False)



# img = data.get_heat_img_in_period(dataset=dataset, data_key='norm_'+data_key,
#                                 t_start=periods[dataset][0]+timedelta(seconds=35),
#                                 t_end=periods[dataset][0]+timedelta(seconds=65),
#                                 cbar_limit=[0, 5], option='vec',
#                                 nan_thres=None, plot=False,
#                                   dur=1, folder='../figs/hough_realdata/')


# ================================================================================
# Plot the time series data for a pixel
# ================================================================================
# data.plot_time_series_for_pixel(dataset=dataset, data_key=data_key, t_start=None, t_end=None, pixels=[(1,8)])



# ================================================================================
# Downsample data
# ================================================================================
# data.down_sample(dataset=dataset, data_key=data_key,
#                  from_freq=128, to_freq=8, save_name='../datasets/data_09_27_2016/927ff1temp8hz.npy')


# ================================================================================
# Check duplicates
# ================================================================================
# all_files = glob.glob('../datasets/1004_2016/*.npy')
# for f in all_files:
#
#     dataset = f.strip().split('/')[-1].replace('.npy','')
#
#     data.load_npy_data(file_name_str=f, dataset=dataset, data_key='temp_data')
#
#     data.check_duplicates(dataset=dataset, data_key='temp_data',
#                             t_start=periods[dataset][0], t_end=periods[dataset][1])


plt.show()