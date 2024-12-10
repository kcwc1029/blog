import os
from dotenv import load_dotenv
from huggingface_hub import login


load_dotenv()
hf_token = os.getenv('HUGGING_FACE_TOKEN')
login(hf_token, add_to_git_credential=True)
print("登入成功")

   
        
    