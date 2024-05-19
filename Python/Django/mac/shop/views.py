from django.shortcuts import render
from django.http import HttpResponse
from .models import Product
from math import ceil
# Create your views here.
def index(request):
    #prod=Product.objects.all()
    
    # params={'products' : prod, 'nslides' : nslides, 'range' : range(1,nslides)}
    #allprods = ([ prod , range(1,nslides) , nslides ],
    #            [ prod , range(1,nslides) , nslides ])
    allprods = []
    catprods = Product.objects.values('category','product_id')
    cats = {item['category'] for item in catprods}
    for cat in cats:
        prod = Product.objects.filter(category = cat)
        n=len(prod)
        nslides = n//4 + ceil(n/4 - n//4)
        allprods.append([prod,range(1,nslides),nslides])

    params = {"allprods" : allprods}
    return render(request,'shop/index.html',params)
def about(request):
    return render(request,'shop/about.html')
    
