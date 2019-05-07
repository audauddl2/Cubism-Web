package com.kpu.cubism.dao;

import java.util.List;
import javax.inject.Inject;
import org.apache.ibatis.session.SqlSession;
import org.springframework.stereotype.Repository;

import com.kpu.cubism.vo.MemoryVo;

@Repository
public class MemoryDao {
	
	@Inject
    private SqlSession sqlSession;
	
	private static final String namespace ="com.kpu.cubism.MemoryMapper";
	/*
	public List<List<Map<Object, Object>>> getCanvasjsChartData(CanvasjsChartVo vo) {
		return vo.getCanvasjsDataList();
	}
	 */
	
	public List<MemoryVo> getMemoryList(MemoryVo vo) {
		
		//System.out.println("BbsDAO Start =================================================");
		return sqlSession.selectList(namespace + ".getMemoryList", vo);
	}
	
	public List<MemoryVo> getMemoryChart(MemoryVo vo) {
		
		//System.out.println("BbsDAO Start =================================================");
		return sqlSession.selectList(namespace + ".getMemoryChart", vo);
	}
	
}
