from datetime import date
import time

today = date.today()
epoch = time.time()

c = ('{:,}'.format(round(epoch, 4)))
sc = ('{:.2e}'.format(epoch))

print(f"Seconds since January 1, 1970: {c} or {sc} in scientific notation")

print(today.strftime("%b %d %Y"))
