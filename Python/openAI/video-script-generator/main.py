import streamlit  as st
from utils import generate_script
from emotion import analyze_sentiment



##### NOTE: 片腳本生成器 #####
# st.title("影片腳本生成器")

# st.write("早安")# NOTE: 支持markdown
# with st.sidebar:
#     openai_api_key = st.text_input("请输入OpenAI API密钥：", type="password")
#     st.markdown("[获取OpenAI API密钥](https://platform.openai.com/account/api-keys)")

# subject = st.text_input("💡 请输入视频的主题")
# video_length = st.number_input("⏱️ 请输入视频的大致时长（单位：分钟）", min_value=0.1, step=0.1)
# creativity = st.slider("✨ 请输入视频脚本的创造力（数字小说明更严谨，数字大说明更多样）", min_value=0.0,
#                        max_value=1.0, value=0.2, step=0.1)
# submit = st.button("生成脚本")

# if submit and not subject:
#     st.info("请输入视频的主题")
#     st.stop()
# if submit and not video_length >= 0.1:
#     st.info("视频长度需要大于或等于0.1")
#     st.stop()
# if submit:
#     with st.spinner("AI正在思考中，请稍等..."):
#         title, script = generate_script(subject, video_length, creativity, openai_api_key)
#     st.success("视频脚本已生成！")
#     st.subheader("🔥 标题：")
#     st.write(title)
#     st.subheader("📝 视频脚本：")
#     st.write(script)


# Streamlit 界面設計
st.title("文本情感分析工具")
st.write("輸入一段文字，讓 AI 幫你分析其情感傾向：正面、中性或負面。")

# 側邊欄輸入 API 金鑰
with st.sidebar:
    openai_api_key = st.text_input("輸入 OpenAI API 金鑰：", type="password")
    st.markdown("[如何獲取 OpenAI API 金鑰](https://platform.openai.com/account/api-keys)")

# 文本輸入框
text_to_analyze = st.text_area("請輸入要分析的文本：", height=200)

# 提交按鈕
analyze_button = st.button("分析文本情感")

# 顯示結果
if analyze_button:
    if not text_to_analyze.strip():
        st.warning("請輸入文本以進行情感分析！")
    elif not openai_api_key:
        st.warning("請輸入有效的 OpenAI API 金鑰！")
    else:
        try:
            # 調用情感分析函式
            sentiment, confidence = analyze_sentiment(text_to_analyze, openai_api_key)
            st.success("分析完成！")
            st.write("### 分析結果：")
            st.write(f"- **情感分類**：{sentiment}")
            st.write(f"- **置信度分數**：{confidence}")
        except Exception as e:
            st.error(f"分析過程中發生錯誤：{e}")