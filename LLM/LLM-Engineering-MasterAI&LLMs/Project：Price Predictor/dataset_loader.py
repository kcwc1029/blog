from datasets import load_dataset

def load_amazon_dataset():
    dataset = load_dataset("McAuley-Lab/Amazon-Reviews-2023", f"raw_meta_Appliances", split="full", trust_remote_code=True)
    print(f"Number of Appliances: {len(dataset):,}") # Number of Appliances: 94,327
    return dataset

if __name__ == "__main__":
    dataset = load_amazon_dataset()
    # NOTE: Investigate
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

    


