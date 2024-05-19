 cv.cvtColor(frame,cv.COLOR_BGR2GRAY)
        _,imgInv = cv.threshold(imgGray,50,255,cv.THRESH_BINARY_INV)
        frame = cv.bitwise_and(frame,imgInv)
        frame = cv.bitwise_or(frame,imgCanvas)