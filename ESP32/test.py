import time
from machine import Pin, ADC

ADC_PIN=Pin(36)
adc = ADC(ADC_PIN)
adc.width(ADC.WIDTH_9BIT)
adc.atten(ADC.ATTN_11DB)

while True:
    gsr = adc.read()
    print(gsr)
    time.sleep(1)