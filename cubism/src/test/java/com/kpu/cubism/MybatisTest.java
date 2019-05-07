package com.kpu.cubism;

import javax.inject.Inject;

import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.junit.Test;

public class MybatisTest {
	@Inject
    private SqlSessionFactory sqlFactory;
    
    @Test
    public void testFactory(){
        System.out.println("\n >>>>>>>>>> sqlFactory ��� : "+sqlFactory);
    }
    
    @Test
    public void testSession() throws Exception{
        
        try(SqlSession session = sqlFactory.openSession()){
            
            System.out.println(" >>>>>>>>>> session ��� : "+session+"\n");
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
