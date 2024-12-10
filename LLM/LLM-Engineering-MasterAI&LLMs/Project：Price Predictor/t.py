"""
安裝套件：pip install faiss-gpu
"""
import os
import glob
from dotenv import load_dotenv

from huggingface_hub import login
from datasets import load_dataset, Dataset, DatasetDict
import matplotlib.pyplot as plt

##### NOTE: Log in to HuggingFace #####
load_dotenv()  # 載入 .env 文件中的環境變數
hf_token  = os.getenv('HUGGING_FACE_TOKEN')  
login(hf_token, add_to_git_credential=True)


dataset = load_dataset("McAuley-Lab/Amazon-Reviews-2023", f"raw_meta_Appliances", split="full", trust_remote_code=True)
print(f"Number of Appliances: {len(dataset):,}") # Number of Appliances: 94,327

# Investigate
# 會發現遞2數據，是沒有價格的
datapoint = dataset[2]
print(datapoint["price"])
# 調查整體數據集，有幾筆是有價格的
prices = 0
for datapoint in dataset:
    try:
        price = float(datapoint["price"])
        if price > 0:
            prices += 1
    except ValueError as e:
        pass
print(f"有價格的資料數：{prices:,}, 百分比：{prices/len(dataset)*100}")


##### NOTE: 視覺化price的部分 #####
prices = []
lengths = []

for datapoint in dataset:
    try:
        price = float(datapoint["price"])
        if price > 0:
            prices.append(price)
            contents = datapoint["title"] + str(datapoint["description"]) + str(datapoint["features"]) + str(datapoint["details"])
            lengths.append(len(contents))
    except ValueError as e:
        pass
plt.figure(figsize=(15, 6))
plt.title(f"Lengths: Avg {sum(lengths)/len(lengths):,.0f} and highest {max(lengths):,}\n")
plt.xlabel('Length (chars)')
plt.ylabel('Count')
plt.hist(lengths, rwidth=0.7, color="lightblue", bins=range(0, 6000, 100))
plt.show()



