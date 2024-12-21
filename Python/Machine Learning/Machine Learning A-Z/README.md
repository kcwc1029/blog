## 簡單線性回歸

![upgit_20241219_1734602115.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241219_1734602115.png)

-   [simple_linear_regression.ipynb]("./線性回歸(simple Linear regression)/simple_linear_regression.ipynb")

### 1. 普通最小平方法 (Ordinary Least Squares, OLS)

![upgit_20241219_1734602354.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241219_1734602354.png)

## 2. 多元線性回歸(Multiple_Linear_Regression)

![upgit_20241219_1734608021.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241219_1734608021.png)

![upgit_20241219_1734608030.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241219_1734608030.png)

![upgit_20241219_1734608511.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241219_1734608511.png)

-   [Multiple_Linear_Regression.ipynb]("./多元線性回歸(Multiple Linear Regression)/Multiple_Linear_Regression.ipynb")

## 多項式迴歸(Polynomial Linear Regression)

-   屬於非線性的模型，用於預測具有非線性關係的因變量(y)。它通過加入自變量的高次項來建模複雜的關係。
-   [polynomial_linear_regression.ipynb]("./多項式迴歸(Polynomial Linear Regression)/polynomial_linear_regression.ipynb")

## SVR(Support Vector Regression)變體支援向量機

-   SVR (Support Vector Regression) 是支援向量機 (SVM, Support Vector Machine) 的一種變體，用於處理迴歸問題。

![upgit_20241220_1734692979.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241220_1734692979.png)

-   非線性核 SVR (Non-linear Kernel SVR)：基於核函數的擬合方式，特別適合非線性迴歸問題
-   [support_vector_regression.ipynb]("./變體支援向量機(Support Vector Regression, SVR)/support_vector_regression.ipynb")

## 決策樹(Decision Tree)

![upgit_20241220_1734696140.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241220_1734696140.png)

![upgit_20241220_1734696191.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241220_1734696191.png)

-   [decision_tree.ipynb]("./決策樹(Decision Tree)/decision_tree.ipynb")

## 隨機森林(Random Forest)

-   隨機森林是一種基於決策樹的集成學習方法。
-   它通過構建多個決策樹並將它們的結果進行平均 (迴歸) 或投票 (分類)，來提升模型的準確性和穩健性。
-   STEP 1: 從訓練數據集中隨機選取 K 個數據點
-   STEP 2: 使用這些 K 個數據點構建一棵決策樹
-   STEP 3: 選擇要構建的樹的數量平均，重複 STEP1 STEP2
-   [random_forest.ipynb]("./隨機森林(Random Forest)/random_forest.ipynb")

## R 平方

![upgit_20241220_1734700154.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241220_1734700154.png)

## 邏輯回歸(Logistic Regression)

-   用於分類問題，預測類別
-   使用 Sigmoid 函數 將線性方程的輸出轉換為概率
-   預測結果為概率（介於 0 和 1 之間）

![upgit_20241220_1734700524.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241220_1734700524.png)

![upgit_20241220_1734700621.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241220_1734700621.png)

![upgit_20241220_1734700469.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241220_1734700469.png)

-   [logistic_regression.ipynb]("./邏輯回歸(Logistic Regression)/logistic_regression.ipynb")

## KNN (K-Nearest Neighbors)

-   它不需要訓練過程
-   給定一個數據點，找到距離它最近的 K 個鄰居，然後根據這些鄰居的標籤進行預測。
-   工作流程
    -   計算待測數據點與所有訓練數據的距離。
    -   找到距離最近的 K 個鄰居。
    -   根據鄰居的標籤進行分類或回歸：
        -   分類：選擇 K 個鄰居中出現最多的標籤（多數決）。
        -   回歸：對 K 個鄰居的標籤取平均值。

![upgit_20241220_1734703075.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241220_1734703075.png)

![upgit_20241220_1734703090.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241220_1734703090.png)

![upgit_20241220_1734703099.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241220_1734703099.png)
