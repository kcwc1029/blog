## 1. machine learning

![upgit_20241215_1734271990.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241215_1734271990.png)

![upgit_20241216_1734325469.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734325469.png)

![upgit_20241216_1734325548.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734325548.png)

## 2. 監督式學習（Supervised Learning）

-   監督式學習需要標註過的數據（有輸入和對應的輸出），模型學習數據中輸入和輸出之間的映射關係。
-   讓模型能夠根據新的輸入預測對應的輸出。
-   類型：
    -   分類（Classification）：預測類別，例如判斷圖片中的物體是貓還是狗。
    -   回歸（Regression）：預測連續值，例如房價、溫度等。
-   應用： 電郵垃圾郵件分類 - 房價預測 - 醫學影像診斷
    ![upgit_20241216_1734325589.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734325589.png)

## 3. 非監督式學習（Unsupervised Learning）

-   非監督式學習處理未標註的數據，目的是讓模型發現數據中的潛在結構或模式。
-   將數據進行分組或降維，找出潛在規律。
-   類型：
    -   聚類（Clustering）：將相似的數據分成同一群組，例如顧客分群。
    -   關聯規則學習（Association Rule Learning）：發現數據中的關聯性，例如購物籃分析。
-   應用： - 市場顧客分群 - 異常檢測（如金融詐欺） - 購物推薦系統
    ![upgit_20241216_1734325730.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734325730.png)

## 4. 遷移學習（Transfer Learning）

-   遷移學習是一種將**在一個任務中學到的知識**，應用到**另一個相關任務**上的方法。
-   減少訓練時間，讓模型在小數據集上達到良好效果。
-   應用：
    -   圖像識別：使用訓練好的 ResNet 或 VGG 模型進行新圖像分類。
    -   自然語言處理（NLP）：使用預訓練語言模型如 BERT 或 GPT 進行新任務微調。

![upgit_20241216_1734325822.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734325822.png)

## 5. 強化學習（Reinforcement Learning, RL）

-   強化學習是一種基於**試錯法**的學習方式，智能體（Agent）與環境互動，透過獎勵和懲罰來學會最佳策略。
-   讓智能體學會如何在不同狀態下選擇動作，以最大化累積獎勵。
-   特點：
    -   學習過程沒有標準答案，而是根據獎勵信號來學習。
    -   適合多步驟決策問題。
-   應用：
    -   遊戲 AI：如 AlphaGo、Dota 2 AI 等。
    -   機器人控制：讓機器人學會走路或抓取物體。
    -   自動駕駛：學會在道路上決策。

![upgit_20241216_1734326491.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734326491.png)

## 6. Splitting Data

![upgit_20241216_1734327556.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734327556.png)

## 7. Modelling - Picking the Model

![upgit_20241216_1734327699.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734327699.png)

### 7.1. 結構化數據（Structured Data）

-   結構化數據是經過整理、具有明確行和列的數據，通常存儲在表格或資料庫中，例如 Excel、CSV 檔案等。
-   見於預測任務，例如銷售預測、分類任務等。
-   推薦模型：
    -   Random Forest：一種集成學習模型，通過多個決策樹的投票來提升準確率，適用於分類和回歸問題。
    -   XGBoost（Extreme Gradient Boosting）：一種高效且準確的梯度提升演算法，廣泛應用於各種競賽和實際場景。
    -   CatBoost：對分類特徵（Categorial Features）有優化，適合處理有類別型變數的數據。

### 7.2. 非結構化數據（Unstructured Data）

-   非結構化數據是沒有固定格式的數據，通常包括圖片、音頻、影片、文本等類型。
-   圖片識別、語音識別、自然語言處理（NLP）等。
-   推薦模型：
    -   Transfer Learning（遷移學習）：
        -   將在大型數據集上訓練好的模型（如 ImageNet）遷移到新任務上，適合小數據集的場景。
        -   範例：微調已訓練的模型來處理特定任務，如圖像分類。
    -   Deep Learning（深度學習）：
        -   使用神經網路（如 CNN、RNN）處理非結構化數據。
        -   常用於圖像識別、語音識別、文本分析等。
        -   範例：ResNet、VGG（圖像）、BERT（文本）。

![upgit_20241216_1734327762.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734327762.png)

## 8. Model Tuning

![upgit_20241216_1734328028.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734328028.png)

## 9. Model Comparison

![upgit_20241216_1734328122.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734328122.png)

### 9.1. 正常表現（左側，綠色勾勾 ✅）：

-   型在訓練集和測試集上都表現良好。

### 9.2. 欠擬合（右上，藍色區域，Underfitting ❌）

-   模型在訓練集和測試集上的性能都很低。
-   原因：
    -   模型太過簡單，無法捕捉數據中的特徵和模式。
    -   可能是使用的模型過於基礎，或者訓練不夠充分。
-   解決方案：
    -   使用更複雜的模型（例如從線性模型升級到樹模型或神經網路）。
    -   增加特徵工程，改善數據品質。
    -   增加訓練時間或調整超參數。

### 9.3. 過擬合（右下，青色區域，Overfitting ❌）

-   現象：模型在訓練集上表現極佳，但在測試集上的性能下降或不自然地高。
-   原因：模型過於複雜，記住了訓練集的細節和噪音，而無法泛化到新數據。
-   解決方案：
    -   使用正則化方法（如 L1、L2 正則化）來約束模型。
    -   簡化模型結構或使用較小的模型。
    -   增加訓練數據，讓模型學到更通用的模式。
    -   使用交叉驗證（Cross-Validation）來檢查模型泛化能力。

![upgit_20241216_1734328285.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734328285.png)

## 10. Types of Evaluation(metrics)

![upgit_20241216_1734326885.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734326885.png)

### 10.1. 分類 (Classification) 指標

#### 10.1.1. Accuracy（準確率）

-   模型預測正確的樣本數量佔總樣本數的比例
-   適用場景：當數據集的類別分布均衡時（例如 50% 是 A 類，50% 是 B 類）。
-   缺點：對於類別不平衡的數據集效果不好，容易偏向佔比多的類別。\*\*\*\*
-   $$Accuracy = \frac{\text{正確預測的樣本數}}{\text{總樣本數}}$$

#### 10.1.2. Precision（精確率）

-   定義：模型預測正確的樣本數量佔總樣本數的比例。
-   適用場景：當 錯誤預測為正類的代價較高 時，例如醫療診斷中的誤報。
-   $$Precision = \frac{\text{真陽性 (TP)}}{\text{真陽性 (TP) + 假陽性 (FP)}}$$

#### 10.1.3. Recall（召回率）

-   定義：實際正類樣本中，被模型正確預測出來的比例。
-   適用場景：當 漏報代價較高 時，例如癌症檢測中漏診的問題。
-   $$Recall = \frac{\text{真陽性 (TP)}}{\text{真陽性 (TP) + 假陰性 (FN)}}$$

### 10.2. 回歸 (Regression) 指標

#### 10.2.1. Mean Absolute Error (MAE)

-   定義：預測值與真實值之間的絕對誤差的平均值。
-   特點：簡單直觀，誤差不會被放大。
-   $$MAE=1n∑i=1n∣yi−y^i∣MAE = \frac{1}{n} \sum_{i=1}^n |y_i - \hat{y}_i|$$

#### 10.2.2. Mean Squared Error (MSE)

-   定義：預測值與真實值之間的平方誤差的平均值。
-   特點：誤差被平方，強調大誤差的影響。
-   缺點：單位變化（平方後的數值不直觀）。
-   $$MSE=1n∑i=1n(yi−y^i)2MSE = \frac{1}{n} \sum_{i=1}^n (y_i - \hat{y}_i)^2$$

#### 10.2.3. Root Mean Squared Error (RMSE)

-   定義：MSE 的**平方根**，單位與原數據相同，更直觀。
-   特點：與 MAE 相比，更加強調大誤差。
-   $$RMSE=1n∑i=1n(yi−y^i)2RMSE = \sqrt{\frac{1}{n} \sum_{i=1}^n (y_i - \hat{y}_i)^2}$$

## 11. Tools We Will Use

![upgit_20241216_1734328347.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734328347.png)

## 12. scikit-learn workflow

![upgit_20241215_1734272200.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241215_1734272200.png)

## 13. Scikit-learn datasets

我們將使用 2 個數據集進行演示：

-   heart_disease：classification dataset -> 預測某人是否患有心臟病
-   boston_df：regression dataset -> 預測波士頓城市的房價中位數

## 14. Pandas 資料框架 (DataFrame)

-   head(n)：顯示前 n 行。
-   tail(n)：顯示 DataFrame 的最後幾行。
-   DataFrame.info()：顯示資料框的基本資訊(行數、列數、資料類型(dtype))
-   DataFrame.describe()：統計摘要，包括平均值、標準差、最小值、最大值等。
-   DataFrame.columns：顯示 DataFrame 的所有列標籤。
-   DataFrame.index：顯示 DataFrame 的行索引。
-   DataFrame.shape：顯示 DataFrame 的形狀 (行數, 列數)。
-   DataFrame[column].value_counts()：對特定列的值進行計數。
    ![upgit_20241215_1734273604.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241215_1734273604.png)

## 15. 選擇模型(model)/估算器(estimator)

![upgit_20241215_1734274317.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241215_1734274317.png)

-   在機器學習的語境中，model 和 estimator 雖然相關，但它們有一些細微的區別。
-   Estimator(估算器)
    -   是未經訓練的算法，用於創建機器學習模型
    -   指機器學習演算法的類別或工具（例如：LinearRegression、SVC）。
-   Model(模型)
    -   經過訓練 (training) 後的機器學習算法結果
    -   是「烘焙完成的麵包」，已經完成學習並準備提供結果。
    -   eg：訓練完成的 線性回歸模型、 決策樹模型 etc.
-   可以根據[Scikit-Learn machine learning map](https://scikit-learn.org/stable/machine_learning_map.html) 進行選擇。

## 16. Project：patient heart disease

-   [patient_heart_disease_classfication.ipynb](./patient%20heart%20disease/patient_heart_disease_classfication.ipynb)

## 17. Ensemble

-   資料來源：[台大資訊 人工智慧導論 | FAI 2.4: Ensemble Bagging](https://www.youtube.com/watch?v=sw2BpP8oAH0&t=711s)
-   多個弱模型組合：將多個「弱模型」（簡單但不一定完美的模型，例如決策樹）集合起來。

### 17.1. Bagging（Bootstrap Aggregating）

-   透過隨機抽樣產生多個子數據集，並在每個子數據集上訓練一個模型。最終的預測結果是所有模型輸出的平均值（回歸）或投票（分類）。
-   特點：能夠降低過擬合風險，適合高方差的模型。
-   範例：隨機森林 (Random Forest)。

### 17.2. Random Forest

![upgit_20241216_1734349449.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241216_1734349449.png)

-   Random Forest (RF) = random sampling + decision tree
-   數據隨機性：透過 Bootstrap 抽樣法，隨機從原始資料集中抽取子樣本，並在每個子樣本上建立一棵決策樹。
-   特徵隨機性：在每次節點分裂時，隨機選取部分特徵進行分裂，而不是使用所有特徵。
-   最終結果：
    -   對於 分類 問題：多棵決策樹的結果透過「投票」決定最終分類結果。
    -   對於 回歸 問題：多棵決策樹的輸出取平均值作為最終預測結果。

## 18. 處裡文字編碼(one-hot)

-   [one_hot_car_sales.ipynb](./care%20sales/one_hot_car_sales.ipynb)

## 19. 處裡缺失值

-   [missing_value_care_sales.ipynb](./care%20sales//missing_value_care_sales.ipynb)

## 20. 針對問題，選擇一個對的 estimator

-   [heart_diseas_choose_model](./choose%20differt%20model/heart_diseas_choose_model.ipynb)
-   [California_choose_model.ipynb](./choose%20differt%20model/California_choose_model.ipynb)

## 21. Deep Learning and Unstructured Data

![upgit_20241219_1734590968.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241219_1734590968.png)

![upgit_20241219_1734591012.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241219_1734591012.png)

![upgit_20241219_1734591100.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241219_1734591100.png)

### 21.1. 為什麼要選擇 TensorFlow 作為深度學習框架

-   TensorFlow 支援 GPU 運行，加速計算。
-   TensorFlow 提供許多內建的深度學習模型，這些模型是預先訓練好的
-   TensorFlow 是一個完整的技術堆疊，可以處理
    -   數據預處理（preprocess）：對數據進行清理和格式化。
    -   模型構建（model）：訓練和測試深度學習模型。
    -   部署（deploy）：將模型部署到生產環境中，例如移動設備或雲端服務。
-   `pip install tensorflow`

## 22. Project：犬種識別(Dog Breed Identification)

-   資料來源：https://www.kaggle.com/c/dog-breed-identification/data

-   data set 存放方式

![upgit_20241219_1734592145.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/12/upgit_20241219_1734592145.png)
