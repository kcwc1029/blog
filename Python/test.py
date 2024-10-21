import logging

# 設定 logging 等級為 DEBUG，這樣所有等級的訊息都會顯示
logging.basicConfig(level=logging.WARNING)

logging.debug('This is a DEBUG message')    # 顯示調試資訊
logging.info('This is an INFO message')     # 顯示一般資訊
logging.warning('This is a WARNING message') # 顯示警告資訊
logging.error('This is an ERROR message')   # 顯示錯誤資訊
logging.critical('This is a CRITICAL message') # 顯示嚴重錯誤資訊
