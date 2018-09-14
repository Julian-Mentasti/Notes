package arch.sm213.machine.student;
import machine.AbstractMainMemory;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;
import java.util.Arrays;

public class MainMemoryTest {

    @Test
    public void isAccessAlstignedTest() {
        MainMemory memory = new MainMemory(2);
        int length = 2;

        //what if its outside the byte capacity
        assertTrue(memory.isAccessAligned(0,length));
        assertFalse(memory.isAccessAligned(1, length));
            assertTrue(memory.isAccessAligned(0, length+1));
    }

    @Test
    public void bytesToIntegerTest() {
        MainMemory memory = new MainMemory(4);
        assertEquals(0,memory.bytesToInteger((byte) 0x0, (byte) 0x0, (byte) 0x0, (byte) 0x0));
        assertEquals(1, memory.bytesToInteger((byte) 0x0, (byte) 0x0, (byte) 0x0, (byte) 0x1));
        assertEquals(257, memory.bytesToInteger((byte) 0x0, (byte) 0x0, (byte) 0x1, (byte) 0x1));
        assertEquals(-1,memory.bytesToInteger((byte) 0xff, (byte) 0xff, (byte) 0xff, (byte) 0xff));
        assertEquals(128,memory.bytesToInteger((byte) 0x0, (byte) 0x0, (byte) 0x0, (byte) 0x80));
    }

    @Test
    public void integertobytes() {
        MainMemory memory = new MainMemory(4);
        byte[] null_byte = {(byte) 0x0,  (byte) 0x0,  (byte) 0x0,  (byte) 0x0};
        byte[] null_byte_res = memory.integerToBytes(0);

        for(int i=0; i<4; ++i)
            assertEquals(null_byte[i],null_byte_res[i]);

        byte[] one_byte  = {(byte) 0x0,  (byte) 0x0,  (byte) 0x0,  (byte) 0x1};
        byte[] one_byte_res = memory.integerToBytes(1);

        for(int i=0; i<4; ++i)
            assertEquals(one_byte[i],one_byte_res[i]);


        byte[] full_byte = {(byte) 0xff, (byte) 0xff, (byte) 0xff, (byte) 0xff};
        byte[] full_byte_res = memory.integerToBytes(-1);
        
        for(int i=0; i<4; ++i)
            assertEquals(full_byte[i],full_byte_res[i]);

        byte[] byte_128 = {(byte) 0x0, (byte) 0x0, (byte) 0x0, (byte) 0x80};

        //System.out.println(Arrays.toString(byte_128));

        byte[] byte_128_res = memory.integerToBytes(128);
       
        for(int i=0; i<4; ++i)
            assertEquals(byte_128[i],byte_128_res[i]);

    }


    @Test
    public void getTest() {
        MainMemory memory = new MainMemory(3);
        byte [] bs_0 = {(byte) 0x0, (byte) 0x0};
        byte [] bs_1 = {(byte) 0x1};
        byte [] bs_2 = {(byte) 0x10, (byte) 0xf0};
        try {
            byte [] rbs_0 = memory.get(0,2);
            memory.set(0,bs_2);
            byte [] rbs_a = memory.get(0,2);
            memory.set(0,bs_1);
            byte [] rbs_b = memory.get(0,1);
            memory.set(1,bs_1);
            byte [] rbs_c = memory.get(1,1);
            for (int i = 0; i < 2; i++) {
                assertEquals(bs_0[i], rbs_0[i]);
            }
            for (int i = 0; i < 2; i++) {
                assertEquals(bs_2[i], rbs_a[i]);
            }
            assertEquals(bs_1[0], rbs_b[0]);
            assertEquals(bs_1[0], rbs_c[0]);
        } catch (AbstractMainMemory.InvalidAddressException e) {
            assertTrue(false);
        }
        
        try {
            memory.get(0,4);
            assertTrue(false);
        } catch (AbstractMainMemory.InvalidAddressException e) {
            assertTrue(true);
        }
        try {
            memory.get(1,3);
            assertTrue(false);
        } catch (AbstractMainMemory.InvalidAddressException e) {
            assertTrue(true);
        }
        try {
            memory.get(3,2);
            assertTrue(false);
        } catch (AbstractMainMemory.InvalidAddressException e) {
            assertTrue(true);
        }
        try {
            memory.get(-3,2);
            assertTrue(false);
        } catch (AbstractMainMemory.InvalidAddressException e) {
            assertTrue(true);
        }
    }

    @Test
    public void setTest() {
        MainMemory memory = new MainMemory(2);
        byte [] bs_2 = {(byte) 0xaa, (byte) 0xef};
        byte [] bs_1 = {(byte) 0x3a};
        try {
            memory.set(0,bs_2);
            byte [] rbs_a = memory.get(0,2);
            memory.set(0,bs_1);
            byte [] rbs_b = memory.get(0,1);
            memory.set(1,bs_1);
            byte [] rbs_c = memory.get(1,1);
            for (int i = 0; i < 2; i++) {
                assertEquals(bs_2[i], rbs_a[i]);
            }
            assertEquals(bs_1[0], rbs_b[0]);
            assertEquals(bs_1[0], rbs_c[0]);
        } catch (AbstractMainMemory.InvalidAddressException e) {
            assertTrue(false);
        }
        try {
            memory.set(2,bs_2);
            assertTrue(false);
        } catch (AbstractMainMemory.InvalidAddressException e) {
            assertTrue(true);
        }
        try {
            memory.set(1,bs_2);
            assertTrue(false);
        } catch (AbstractMainMemory.InvalidAddressException e) {
            assertTrue(true);
        }
        try {
            memory.set(3,bs_2);
            assertTrue(false);
        } catch (AbstractMainMemory.InvalidAddressException e) {
            assertTrue(true);
        }
        try {
            memory.set(-2,bs_2);
            assertTrue(false);
        } catch (AbstractMainMemory.InvalidAddressException e) {
            assertTrue(true);
        }
        
        try { 
            memory.set(3,bs_1);
        } catch (AbstractMainMemory.InvalidAddressException e) {
            assertTrue(true);
        }
    }


}
