# Hugging Face: https://huggingface.co/Helsinki-NLP/opus-mt-tc-big-en-pt
import torch
from transformers import AutoTokenizer, AutoModelForSeq2SeqLM

tokenizer = AutoTokenizer.from_pretrained("Helsinki-NLP/opus-mt-tc-big-en-pt")
model = AutoModelForSeq2SeqLM.from_pretrained("Helsinki-NLP/opus-mt-tc-big-en-pt")

src = input("Digite: ")

input_ids = tokenizer(src, return_tensors="pt").input_ids

output_ids = model.generate(input_ids)[0]

target = tokenizer.decode(output_ids)

print(f"Resposta: {target}")    