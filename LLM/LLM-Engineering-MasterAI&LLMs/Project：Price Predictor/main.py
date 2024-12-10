
# 登入hugging face
import config
# 載入資料
from dataset_loader import *

##### NOTE: 視覺化price的部分 #####
from visualize import *
dataset = load_amazon_dataset()
visualize_lengths_and_prices(dataset)
