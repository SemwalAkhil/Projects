from django.http import HttpResponse
from django.shortcuts import render

def index(request):
	return render(request,"index.html")
	
def analyse(request):
	djtext=request.POST.get("text","default")
	removepunc=request.POST.get("removepunc","off")	
	capfirst=request.POST.get("capfirst","off")
	newlineremove=request.POST.get("newlineremove","off")
	spaceremove=request.POST.get("spaceremove","off")
		
	if (removepunc=="on"):
		djtext=removePunc(djtext)
	if (capfirst=="on"):
		djtext=capFirst(djtext)
	if (newlineremove=="on"):
		djtext=removeNewLine(djtext)
	if (spaceremove=="on"):
		djtext=extraSpaceRemove(djtext)
	
	count=charCount(djtext)
	params={"newText":djtext , "count":count}
	return render(request,"analyse.html",params)
	
def removePunc(djtext):
	newText=""	
	symbols='''!()-[]{};:'"\,<>./?@#$%^&*_~'''
	for char in djtext:
		if char not in symbols:
			newText+=char
	return newText

def capFirst(djtext):
	newText=""
	caps=True
	for i in djtext:
		if caps:
			newText+=i.upper()
			caps=False
		elif i==" ":
			newText+=i
			caps=True
		else:
			newText+=i
	return newText

def removeNewLine(djtext):
	newText=""
	for char in djtext:
		if (char != "\n" and char!="\r") :
			newText+=char
	return newText

def charCount(djtext):
	return len(djtext)
	
def extraSpaceRemove(djtext):
    newText = ""
    is_space = False  # Flag to track if the previous character was a space
    for char in djtext:
        if char != " " and char != "\n":
            newText += char
            is_space = False
        elif char == " " and not is_space:
            newText += char
            is_space = True
        elif char == "\n" and not is_space:
            newText += char
            is_space = True
    return newText