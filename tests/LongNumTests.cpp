#include "LongNumMod.hpp"
#include <gtest/gtest.h>

class LongNumberTests : public ::testing::Test {
protected:
    LongNumber ln1;
    LongNumber ln2;

    void SetUp() override {
        ln1 = LongNumber("23A6F9B50D34A7E071EC59F90C128E775FA3C0F3E1CDD13C963C64166D0DE107E98E1523DD70C92724A35E429E741E036655F4E4FA267D08079F4ABFB2D2F286AA6BCA5BFC1B135B0C3D6F4E53F5ED5381815"); 
        ln2 = LongNumber("7FD6C21CC86C06C7219C96A88141C47FEBEDD1B1742A9A2D9F4A15A8F9913088360E7313C8AA5DFA0009DFFCFB52B1C6EDBD39213D8E3F25FD40098F1CC5226D4AB6ED52FDADB34D7E4B85888C9422D"); 
    }
};

TEST_F(LongNumberTests, AdditionOperator) {
    LongNumber ans = ln1 + ln2;
    EXPECT_EQ(ans.toHexString(), "23A6FA34E3F6C4A8DDF3211AA8A936F8A16840DFCF9F82B0C0D691B5B7238A017ABE9D59EBE3DCEFCF015842A8541AFEB907BBD2B75F9E4595DE70BCF2DC81A36F8E37A6B3086658B9F0BCCC9F7B75E015A42");
}

TEST_F(LongNumberTests, SubstractionOperator) {
    LongNumber ans = ln1 - ln2;
    EXPECT_EQ(ans.toHexString(), "23A6F93536728B1805E592D76F7BE5F61DDF4107F3FC1FC86BA2367722F8380E585D8CEDCEFDB55E7A4564429494210813A42DF73CED5BCA796024C272C96369E5495D11452DC05D5E8A21D0087064C6ED5E8");
}

TEST_F(LongNumberTests, MultiplicationOperator) {
    LongNumber ans = ln1 * ln2;
    EXPECT_EQ(ans.toHexString(), "11CDBE7E1A4E2B947725536DCFB06D975C6FF2B93348176FF0CF438EF0B713C2BDF6D53DD0E8503014257D37008002103C1CFA2F8615E0AFF63165D4A661D8B2D6FC451B937A5FF8D296C107FD68AD92FE7D8BF0AEE1F0737FD5661D7D71F6EA6875684EA0B3EABC87BC30E5DE2A3B3E07A57A51FF33A4208830CD1C2CA626B53D88D9DFF5D0C6EC6BD0875CB6C4EF1221D477AC2F73AB32B8E1FBA92BB2018EA5B1");
}

TEST_F(LongNumberTests, DivisionOperator) {
    LongNumber ans = ln1 / ln2;
    EXPECT_EQ(ans.toHexString(), "4764F4");
}

TEST_F(LongNumberTests, ModOperator) {
    LongNumber ans = ln1 % ln2;
    EXPECT_EQ(ans.toHexString(), "228D5CF8C59B5AFEFC36CE381473F2B60715677D1D1A4923517D3011FCCB19220EA7604B47B766553E8C70E2DCF740018A16A44F483F5B65B43CD4A18D0331B3DEE921B4FCF50B4B65505BC7D107131");
}

TEST_F(LongNumberTests, ToSquareOperator) {
    LongNumber ans = ln1.toSquare();
    EXPECT_EQ(ans.toHexString(), "4F715304BFB39ED31F0C3FF145D513E58722935ECF4B0B9384C5D8F32CB28A133A6DF5D48464C318E1186508C38545136F61F815E81ED4AB74C43603BA1D25C15BBD9DAD81EC053FB4DC472C677BC31ACAFB153CFDEC341C1183493BD5E8C45106CC7A23C477EE303483368BF21781FE9FBC2A9B2A5404100ECAAFB77FA92848C67FA6A08A0EB7E7DA44AECC989B8ECE866B687406BFB979AF3247572003469C97D73F1B9");
}

TEST_F(LongNumberTests, GCDOperation) {
    LongNumber ans = gcd(ln1, ln2);
    EXPECT_EQ(ans.toHexString(), "5");
}


TEST_F(LongNumberTests, ConstructorFromHexString) {
    LongNumber num2("40FFFFFFFF0000003E0000003D0000003C0000003B0000003A000000390000003800000037000000360000003500000034000000330000003200000031000000300000002F0000002E0000002D0000002C0000002B0000002A000000290000002800000027000000260000002500000024000000230000002200000021000000200000001F0000001E0000001D0000001C0000001B0000001A000000190000001800000017000000160000001500000014000000130000001200000011000000100000000F0000000E0000000D0000000C0000000B0000000A000000090000000800000007000000060000000500000004000000030000000200000001");
    std::string hexStr = num2.toHexString();
    EXPECT_EQ(hexStr, "40FFFFFFFF0000003E0000003D0000003C0000003B0000003A000000390000003800000037000000360000003500000034000000330000003200000031000000300000002F0000002E0000002D0000002C0000002B0000002A000000290000002800000027000000260000002500000024000000230000002200000021000000200000001F0000001E0000001D0000001C0000001B0000001A000000190000001800000017000000160000001500000014000000130000001200000011000000100000000F0000000E0000000D0000000C0000000B0000000A000000090000000800000007000000060000000500000004000000030000000200000001");
}

TEST_F(LongNumberTests, EqualityOperator) {
    LongNumber num1("104D4A301BD70480050C46201F6AA95018228D200F5CA420252104D4A301BD70480050C46201F6AA95018228D200F5CA420252104D4A301BD70480050C46201F6AA95018228D200F5CA420252104D4A301BD70480050C46201F6AA95018228D200F5CA420252104D4A301BD70480050C46201F6AA95018228D200F5CA420252");
    LongNumber num3(num1);
    LongNumber num2("40FFFFFFFF0000003E0000003D0000003C0000003B0000003A000000390000003800000037000000360000003500000034000000330000003200000031000000300000002F0000002E0000002D0000002C0000002B0000002A000000290000002800000027000000260000002500000024000000230000002200000021000000200000001F0000001E0000001D0000001C0000001B0000001A000000190000001800000017000000160000001500000014000000130000001200000011000000100000000F0000000E0000000D0000000C0000000B0000000A000000090000000800000007000000060000000500000004000000030000000200000001");
    
    EXPECT_EQ(num1, num3);
    EXPECT_NE(num1, num2);
}

TEST_F(LongNumberTests, AdditionAndMultiplicationOperators) {
    LongNumber num1 ("104D4A301BD70480050C46201F6AA95018228D200F5CA420252");
    LongNumber num2;
    
    for(int i = 120; i > 0; i--) 
        num2 = num2 + num1;

    LongNumber temp(120);
    LongNumber num3 = num1 * temp;
    
    EXPECT_EQ(num3, num2);
}

TEST_F(LongNumberTests, LessThanOperator) {
    LongNumber num1("7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
    LongNumber num2("80000000000000000000000000000000800000000000000000000000000000008000000000000000000000000000000");

    EXPECT_TRUE(num2 < num1);
}

TEST_F(LongNumberTests, GreaterThanOperator) {
    LongNumber num1("7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
    LongNumber num2("80000000000000000000000000000000800000000000000000000000000000008000000000000000000000000000000");

    EXPECT_FALSE(num1 < num2);
}

TEST_F(LongNumberTests, ComplexSubtractionOperator) {
    LongNumber num1("40FFFFFFFF0000003E0000003D0000003C0000003B0000003A000000390000003800000037000000360000003500000034000000330000003200000031000000300000002F0000002E0000002D0000002C0000002B0000002A000000290000002800000027000000260000002500000024000000230000002200000021000000200000001F0000001E0000001D0000001C0000001B0000001A000000190000001800000017000000160000001500000014000000130000001200000011000000100000000F0000000E0000000D0000000C0000000B0000000A000000090000000800000007000000060000000500000004000000030000000200000001");
    LongNumber diff = num1 - num1;
    LongNumber expected(0);

    LongNumber num2 ("104D4A301BD70480050C46201F6AA95018228D200F5CA420252");
    LongNumber num3 = num1 + num2 - num2;
   
    EXPECT_EQ(diff, expected);
    EXPECT_EQ(num1, num3);
}

TEST_F(LongNumberTests, MultiplicationAndSquareOperator) {
    LongNumber num("104D4A301BD70480050C46201F6AA95018228D200F5CA420252104D4A301BD70480050C46201F6AA95018228D200F5CA4202");
    LongNumber product = num * num;
    LongNumber square = num.toSquare();
   
    EXPECT_EQ(product, square);
}

TEST_F(LongNumberTests, MultiplicationAndToPowerOfOperators) {
    LongNumber num1 ("104D4A301BD70480050C46201F6AA95018228D200F5CA420252");
    LongNumber num2(num1);
    LongNumber num3 = num2 * num2 * num2 * num2 *num2 * num2 *num2 * num2; 

    LongNumber power("8");
    LongNumber res = num1.toPowerOf(power);

    EXPECT_EQ(res, num3);
}