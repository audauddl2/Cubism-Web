package com.kpu.cubism.dao;

import java.util.Map;

import javax.inject.Inject;

import org.apache.ibatis.session.SqlSession;
import org.springframework.stereotype.Repository;

import com.kpu.cubism.vo.UserVo;

@Repository
public class UserDao {
	
	@Inject
    private SqlSession sqlSession;
	
	private static final String namespace ="com.kpu.cubism.UserMapper";
	
	/*
	 * 사용자 등록
	 * 
	 */
	public int UserRegister(UserVo vo) {
		
		return sqlSession.insert(namespace + ".UserRegister", vo);
	}

	public int UserCheck(Map<String, Object> map) throws Exception {
		
		Map<String, Object> resultMap = (Map<String, Object>)sqlSession.selectOne(namespace + ".UserCheck", map);
		
		int result = Integer.valueOf(String.valueOf(resultMap.get("RESULT")));
		
		return result;
	}
}
