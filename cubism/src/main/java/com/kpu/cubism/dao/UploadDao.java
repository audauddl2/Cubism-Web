package com.kpu.cubism.dao;

import java.util.List;
import java.util.Map;

import javax.inject.Inject;

import org.apache.ibatis.session.SqlSession;
import org.springframework.stereotype.Repository;

import com.kpu.cubism.vo.UploadVo;

@Repository
public class UploadDao {
	
	@Inject
    private SqlSession sqlSession;
	
	private static final String namespace ="com.kpu.cubism.UploadMapper";
	
	/*
	 * 파일 업로드
	 *
	 */
	public void insertFile(Map<String, Object> map) {
		// TODO Auto-generated method stub
		sqlSession.insert(namespace + ".getUploadFile", map);
	}

	/*
	 * 업로드 파일 리스트
	 *
	 */
	public List<UploadVo> getUploadList(UploadVo vo) {
		
		//System.out.println("BbsDAO Start =================================================");
		return sqlSession.selectList(namespace + ".getUploadList", vo);
	}
	/*
	 * 구구단 업로드 파일 리스트
	 *
	 */
	public List<UploadVo> getGGUploadList(UploadVo vo) {
		
		//System.out.println("BbsDAO Start =================================================");
		return sqlSession.selectList(namespace + ".getGGUploadList", vo);
	}
}
