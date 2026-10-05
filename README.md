# ENG1008
Project 1 (Pseudocode)
START
    DECLARE integer sum = 0
    DECLARE integer digits_no
    DECLARE integer input_number
    DECLARE boolean is_binary = TRUE

    WHILE TRUE DO
        PRINT "Enter number of digits: "
        READ digits_no
        PRINT "Enter n-digit number: "
        READ input_number

        IF digits_no > 9 OR digits_no < 0 THEN
            PRINT "Invalid input. Please enter a number between 0 and 9."
            CONTINUE
        ELSE IF digits_no == 0 THEN
            PRINT "Final output:"
            EXIT PROGRAM
        END IF

        PRINT "Final output:"
        BREAK
    END WHILE

    SET remainder = input_number
    
    FOR i FROM 1 TO digits_no DO
        SET power_ten = 10^(digits_no - i)
        SET output_digit = INTEGER_DIV(remainder, power_ten)
        SET remainder = remainder MOD power_ten
        
        PRINT output_digit + " "
        IF output_digit != 0 AND output_digit != 1 THEN
            SET is_binary = FALSE
        END IF
    END FOR

    IF is_binary IS TRUE THEN
        SET remainder = input_number

        FOR j FROM 1 TO digits_no DO
            SET power_ten = 10^(digits_no - j)
            SET power_two = 2^(digits_no - j)
            
            SET digit = INTEGER_DIV(remainder, power_ten)
            SET sum = sum + (digit * power_two)
            SET remainder = remainder MOD power_ten
        END FOR

        PRINT NEWLINE
        PRINT "The decimal equivalent is " + sum
    END IF
END
