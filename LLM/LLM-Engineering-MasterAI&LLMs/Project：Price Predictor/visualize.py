import matplotlib.pyplot as plt

def visualize_lengths_and_prices(dataset):
    prices = []
    lengths = []

    for datapoint in dataset:
        try:
            price = float(datapoint["price"])
            if price > 0:
                prices.append(price)
                contents = datapoint["title"] + str(datapoint["description"]) + str(datapoint["features"]) + str(datapoint["details"])
                lengths.append(len(contents))
        except ValueError:
            pass

    avg_length = sum(lengths) / len(lengths)
    max_length = max(lengths)
    # Plot the distribution of lengths
    plt.figure(figsize=(15, 6))
    plt.title(f"Lengths: Avg {avg_length:,.0f} and highest {max_length:,}\n")
    plt.xlabel('Length (chars)')
    plt.ylabel('Count')
    plt.hist(lengths, rwidth=0.7, color="lightblue", bins=range(0, 6000, 100))
    plt.show()

    # Plot the distribution of prices
    plt.figure(figsize=(15, 6))
    plt.title(f"Prices: Avg {sum(prices)/len(prices):,.2f} and highest {max(prices):,}\n")
    plt.xlabel('Price ($)')
    plt.ylabel('Count')
    plt.hist(prices, rwidth=0.7, color="orange", bins=range(0, 1000, 10))
    plt.show()